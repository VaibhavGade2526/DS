// write application which accept file name from user and Display size of file 

#include<stdio.h>
#include<io.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int fd = 0;
    int iSize = 0;
    char FileName[30];

    printf("Enter file Name :");
    scanf("%s",FileName);

    fd = open(FileName,O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }
     iSize = lseek(fd,0,SEEK_END);
     printf("File size is %d bytes\n",iSize);
    close(fd);
    return 0;

}