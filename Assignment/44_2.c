// write application which accept file name from user and creat that file
#include<stdio.h>
#include<io.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>


int main()
{
    int fd = 0;
    char FileName[30];

    printf("Enter file Name :");
    scanf("%s",FileName);

    fd = open(FileName,O_CREAT,0777);

    if(fd == -1)
    {
        printf("Unable to crate file \n");
    }
    else
    {
        printf("File created successfully\n");
    }
    close(fd);
    return 0;
}