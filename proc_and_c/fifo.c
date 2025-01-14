#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>




int main()
{
    const char path[]="/tmp/fifo";
    if(mkfifo(path,0666)!=0)
    {
        exit(EXIT_FAILURE);
    }

    int fd = open(path,O_RDONLY);

    if(fd <0)
    {
        exit(EXIT_FAILURE);
    }

    while(1)
    {

        char buffer[1024];
        int length= (read(fd,buffer,sizeof((buffer))>0));
        if(length>0)
        {
            write(STDOUT_FILENO,buffer,length);
        }
    }

    close(fd);

    return 0;
}