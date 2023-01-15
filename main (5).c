#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

void main(int argc,char * arg[])
{
    int pid;
    pid = fork();
    if(pid < 0)
    {
        printf("Fork failed\n");
        exit(1);
    }
    
    else if(pid == 0)
    {
        printf("Now in child process and its o/p is\n");
        execlp("ls","ls",NULL);
        exit(0);
    }
    
    else
    {
        printf("Child process created successfully\n");
        printf("\nIts process id is %d\n",getpid());
        wait(NULL);
        printf("Return back to parent process now ready to exit\n");
        exit(0);
    }
}
