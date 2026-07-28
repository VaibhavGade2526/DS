// write application which accept file name from user and read all data from that file and display contents on scrren

#include<stdio.h>
#include<io.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

#define BUFFER_SIZE 1024

int main()
{
    int fd = 0;
    int iRet = 0;
    char FileName[30];
    char Data[BUFFER_SIZE];

    printf("Enter file Name :");
    scanf("%s",FileName);

    fd = open(FileName,O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    while((iRet = read(fd,Data,BUFFER_SIZE)) >0)
    {
        write(1,Data,iRet);
    }
    close(fd);
    return 0;
}