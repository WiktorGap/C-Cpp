#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <pthread.h>

#define DIGIT_COUNT 10

struct context {
    unsigned long count[DIGIT_COUNT];
    pthread_mutex_t mutex;
};

void count_digits(const char *data, size_t start, size_t end, struct context *shared_context) {
    unsigned long local_count[DIGIT_COUNT] = {0};

    for (size_t i = start; i < end; i++) {
        if (data[i] >= '0' && data[i] <= '9') {
            local_count[data[i] - '0']++;
        }
    }

    pthread_mutex_lock(&shared_context->mutex);
    for (int i = 0; i < DIGIT_COUNT; i++) {
        shared_context->count[i] += local_count[i];
    }
    pthread_mutex_unlock(&shared_context->mutex);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file_path> <num_processes>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *file_path = argv[1];
    int num_processes = atoi(argv[2]);

    if (num_processes < 1) {
        fprintf(stderr, "Number of processes must be at least 1.\n");
        return EXIT_FAILURE;
    }

    // Open file
    int fd = open(file_path, O_RDONLY);
    if (fd == -1) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    // Get file size
    off_t file_size = lseek(fd, 0, SEEK_END);
    if (file_size == -1) {
        perror("Failed to determine file size");
        close(fd);
        return EXIT_FAILURE;
    }

    // Map file to memory
    char *data = (char*) mmap(NULL, file_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (data == MAP_FAILED) {
        perror("Failed to map file");
        close(fd);
        return EXIT_FAILURE;
    }

    close(fd);

    // Allocate shared memory for context
    struct context *shared_context = (struct context*) mmap(NULL, sizeof(struct context),
                                          PROT_READ | PROT_WRITE,
                                          MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (shared_context == MAP_FAILED) {
        perror("Failed to allocate shared memory");
        munmap(data, file_size);
        return EXIT_FAILURE;
    }

    // Initialize shared context
    memset(shared_context->count, 0, sizeof(shared_context->count));
    if (pthread_mutex_init(&shared_context->mutex, NULL) != 0) {
        perror("Failed to initialize mutex");
        munmap(shared_context, sizeof(struct context));
        munmap(data, file_size);
        return EXIT_FAILURE;
    }

    // Fork processes
    size_t chunk_size = file_size / num_processes;
    pid_t pids[num_processes];

    for (int i = 0; i < num_processes; i++) {
        size_t start = i * chunk_size;
        size_t end = (i == num_processes - 1) ? file_size : start + chunk_size;

        pids[i] = fork();
        if (pids[i] == -1) {
            perror("Fork failed");
            return EXIT_FAILURE;
        }

        if (pids[i] == 0) { // Child process
            count_digits(data, start, end, shared_context);
            munmap(data, file_size);
            munmap(shared_context, sizeof(struct context));
            exit(EXIT_SUCCESS);
        }
    }

    // Wait for child processes
    for (int i = 0; i < num_processes; i++) {
        waitpid(pids[i], NULL, 0);
    }

    // Print results
    for (int i = 0; i < DIGIT_COUNT; i++) {
        printf("Digit %d: %lu\n", i, shared_context->count[i]);
    }

    // Clean up
    pthread_mutex_destroy(&shared_context->mutex);
    munmap(shared_context, sizeof(struct context));
    munmap(data, file_size);

    return EXIT_SUCCESS;
}
