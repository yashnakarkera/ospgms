#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int g = 0;

void *MythreadFun(void* vargp)
{
    int *myid = (int*)vargp;
    static int s = 0;
    ++s;
    ++g;
    printf("Thread id:%d\t , Static id:%d\t  Global id:%d\t \n",*myid,++s,++g);
}

int main()
{
    int i;
    pthread_t tid;
    for(int i = 0;i<3;i++)
        pthread_create(&tid,NULL,MythreadFun,(void*) &tid);
    pthread_exit(NULL);
    return 0;
}

