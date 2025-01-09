#include <sys/types.h>
#include <sys/wait.h>
#include <uinstd.h>
#include <studio.h>
#include <stdlub>

int main()
{
    pid_t pid = fork();

    if(pid==0)
    {
        //Proces Potomny
        printf("Proces potomny działa (Pid: %d)",getpid());
        sleep(2);
        exit(42);
    }
    else if (pid >0)
    {
        //Proces Rodzicielski 
        int wstatus;
        pid_t wpid = waitpid(pid,&wstatus,0);

        if(wpid>0)
        {
            if(WIFEXITED(wstatus))
            {
                `printf("Proces potomny (PID: %d) zakończył się. Kod wyjścia: %d\n ",wpid,WEXITSTATUS(wstatus));
            }
        }
        else
        {
            perror("waitpid");
        }
    }
    else
    {
        perror("fork");
        return 1;
    }
    return 0;
}