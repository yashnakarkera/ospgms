#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

void main()
{
    int pid;
    pid = fork();
    
    if(!pid)
    {
        printf("Child processs\n");
        printf("Child process id is %d\n",getpid());
        printf("Parent process id is %d\n",getppid());
        printf("Finished with child process\n");
    }
    
    else
    {
        wait(NULL);
        printf("Parent process\n");
        printf("Parent process id is %d\n",getpid());
        printf("Child process id is %d\n",pid);
    }
}

OUTPUT

Child processs
Child process id is 3537
Parent process id is 3533
Finished with child process
Parent process
Parent process id is 3533
Child process id is 3537
