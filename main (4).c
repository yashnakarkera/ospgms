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
