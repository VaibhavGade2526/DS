// write application which accept file name and one string fom user write that string at the end of file

#include<stdio.h>
#include<io.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define BUFFER_SIZE 1024

int main()
{
    int fd = 0;
    char FileName[30];
    char Data[BUFFER_SIZE];

    printf("Enter file name :");
    scanf("%s",FileName);

    printf("Enter String :");
    scanf(" %[^\n]s",Data);

    fd = open(FileName,O_WRONLY | O_APPEND);
    {
        if(fd == -1)
        {
            printf("Unable to open file\n");
            return -1;
        }
    }
      write(fd,Data,strlen(Data));

        close(fd);
        printf("String written successfully at the end if file\n");

    return 0;
}