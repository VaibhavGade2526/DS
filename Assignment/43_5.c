// write a program which accepts file name and one count from user and read that number of character from strating postion

#include<stdio.h>
#include<fcntl.h>
#include<io.h>
#include<stdlib.h>
#include<unistd.h>

#define BUFFER_SIZE 1024
void Display(char FName[], int iSize)
{
    int fd = 0;
    int iRet = 0;
    char Data[BUFFER_SIZE];

    fd = open(FName,O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open file\n");
        return ;
    }
    iRet = read(fd,Data,iSize);

    Data[iRet] = '\0';

    printf("Data from file is : %s\n");

    close(fd);
}
int main()
{
    char FileName[30];
    int iValue = 0;

    printf("Enter file name :");
    scanf("%s",FileName);

    printf("Enter the number of Character :");
    scanf("%d",&iValue);

    Display(FileName,iValue);
    return 0;
}