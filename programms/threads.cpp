#include <string.h>
#include <pthread.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>  
#include <unistd.h> 
#include <stdlib.h> 
#include <sys/types.h>
#include <errno.h>
#include <sys/wait.h>
#define TAB_LENGHT 100
#define DIGIT_COUNT 10

typedef struct shared {
    int tab[TAB_LENGHT];
    pthread_mutex_t mutex;
} shared_t;

void child(shared_t *shr)
{
    int n = 0;
    while (1) {
        pthread_mutex_lock(&shr->mutex);
        for (int i = 0; i < TAB_LENGHT; i++) {
            shr->tab[i] = n;
        }
        pthread_mutex_unlock(&shr->mutex);
        n++;
    }
}

void parent(shared_t *shr)
{
    while (1) {
        pthread_mutex_lock(&shr->mutex);
        for (int i = 0; i < TAB_LENGHT; i++) {
            printf("%d", shr->tab[i]);
        }
        pthread_mutex_unlock(&shr->mutex);
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Użyj: %s <plik> <liczba_procesow>\n", argv[0]);
        return 1;
    }

    int num_processes = atoi(argv[2]);
    if (num_processes <= 0) {
        fprintf(stderr, "Liczba procesów musi być większa od 0.\n");
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Błąd otwierania pliku");
        return 1;
    }

    struct stat st;
    if (fstat(fd, &st) == -1) {
        perror("Błąd pobierania rozmiaru pliku");
        close(fd);
        return 1;
    }

    size_t file_size = st.st_size;
    if (file_size == 0) {
        fprintf(stderr, "Plik jest pusty.\n");
        close(fd);
        return 1;
    }

    char *content = (char*)mmap(NULL, file_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (content == MAP_FAILED) {
        perror("Błąd mapowania pliku");
        close(fd);
        return 1;
    }
    close(fd);

    shared_t *shr = (shared_t*)mmap(NULL, sizeof(shared_t), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (shr == MAP_FAILED) {
        perror("Błąd tworzenia pamięci współdzielonej");
        munmap(content, file_size);
        return 1;
    }

    pthread_mutexattr_t mutexattr;
    if (pthread_mutexattr_init(&mutexattr) != 0 ||
        pthread_mutexattr_setpshared(&mutexattr, PTHREAD_PROCESS_SHARED) != 0 ||
        pthread_mutex_init(&shr->mutex, &mutexattr) != 0) {
        perror("Błąd inicjalizacji mutexa");
        munmap(shr, sizeof(shared_t));
        munmap(content, file_size);
        return 1;
    }

    pid_t pids[num_processes];
    size_t chunk_size = file_size / num_processes;
    for (int i = 0; i < num_processes; i++) {
        size_t start = i * chunk_size;
        size_t end = (i == num_processes - 1) ? file_size : start + chunk_size;
        if ((pids[i] = fork()) == 0) {
            for (size_t j = start; j < end; j++) {
                if (content[j] >= '0' && content[j] <= '9') {
                    int digit = content[j] - '0';
                    pthread_mutex_lock(&shr->mutex);
                    shr->tab[digit]++;
                    pthread_mutex_unlock(&shr->mutex);
                }
            }
            munmap(content, file_size);
            munmap(shr, sizeof(shared_t));
            exit(0);
        } else if (pids[i] < 0) {
            perror("Błąd tworzenia procesu potomnego");
            return 1;
        }
    }

    for (int i = 0; i < num_processes; i++) {
        if (waitpid(pids[i], NULL, 0) == -1) {
            perror("Błąd oczekiwania na proces potomny");
        }
    }

    printf("Wyniki zliczania cyfr:\n");
    for (int i = 0; i < DIGIT_COUNT; i++) {
        printf("Cyfra %d: %d\n", i, shr->tab[i]);
    }

    pthread_mutex_destroy(&shr->mutex);
    munmap(shr, sizeof(shared_t));
    munmap(content, file_size);

    return 0;
}
