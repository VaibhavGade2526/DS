// write application which accept file name from user and open that file in read mode 

#include<stdio.h>
#include<io.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int fd = 0;
    char FileName[30];

    printf("Enter file name :");
    scanf("%s",FileName);

    fd = open(FileName,O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to opn file\n ");
    }
    else
    {
        printf("File opend successfully\n");
        close(fd);
    }
    return 0;

}