#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

void main()
{
    char buff;
    int fd,fd1;
    fd = open("one.txt" , O_RDONLY);
    fd1 = open("two.txt",O_WRONLY|O_CREAT);
    while(read(fd,&buff,1))
    write(fd1,&buff,1);
    printf("File scuucessfully copied\n");
    close(fd);
    close(fd1);
}