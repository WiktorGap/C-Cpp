#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> //fork & close funcs
#include <sys/wait.h> //waitpid
#include <sys/stat> //fstat 
#include <sys/mman.h> //mmap 
#include <ptheard.h> //threads & mutexes
#include <fcntl.h> //open 

#define tab_length 10 
#define _OPEN_SYS 

typdef struct shared
{
    int tab[tab_length];
    phtread_mutex_t mutex; //mutex do synchronizacji dostępu do tej tablicy
}shared_t;

//argc liczba argumentów wiersza poleceń 
//argv tablica argumentów wiersza poleceń 

int main(int argc ,char *argv[])
{
    struct stat statbuf;
    printf("argc=%d\n",argc);

    int fd = open(argv[1],O_RDONLY); //uchwyt do pliku 
    fstat(fd,&statbuf );

    char *content = mmap(NULL,statbuf.st_size,PROT_READ,MAP_SHARED,fd,0);
    printf("content ptr=%p\n",content);
    
    /*Alokacja pamięci współdzielonej*/

    int prot = PROT_READ | PROT_WRITE;
    int vis = MAP_SHARED | MAP_ANONYMUS;
    shared_t *shr = (shared_t*)mmap(NULL,sizeof(shared_t),prot,vis,-1,0);
    if(shr==NULL) return -1;

    for(int=0; i < tab_length;i++)
    {
        shr->tab[i]=0;
    }

    pthread_mutexattr_t mutexattr;
    if (pthread_mutexattr_init(&mutexattr) != 0)
        return -2;

    if (pthread_mutexattr_setpshared(&mutexattr, PTHREAD_PROCESS_SHARED) != 0)
        return -3;
    
    if (pthread_mutex_init(&shr->mutex, &mutexattr) != 0)
    return -4;

    for(int i = 0; i < statbuf.st_size;i++)
    {
        if(content[i]>='0' && content[i]<='9')
        {
            int val = content[i] - '0';
            shr->tab[val]++;
        }
    }

    char *endptr;
    int buff_size = 0;
    int num_args = strtol(argv[2],&endptr,10);
    //Alokacja pamięci na tablicę, która przechowa identyfikatory procesów potomnych
    int *tab = (*int)(malloc(sizeof(int)*num_args));
    printf("%ld",statbuf.st_size);

    if (*endptr != '\0')
    {
        printf("second argument is not a number");
        return -1;
    }

    pid_t pid;
    int rest = statbuf.st_size % num_args;
    int file_pieces = statbuf.st_size / num_args ;


}