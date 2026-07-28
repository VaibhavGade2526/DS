// write aprogram which accepts file name and one character from user and count number of occurrents of that character from that file

#include<stdio.h>
#include<stdlib.h>
#include<io.h>
#include<fcntl.h>
#include<unistd.h>

#define BUFFER_SIZE 1024
int CountChar(char FName[] ,char ch)
{
    int fd = 0;
    int iRet = 0,i = 0,iCount = 0;
    char Data[BUFFER_SIZE];

    fd = open(FName, O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open file ");
        return -1;
    }

    while((iRet = read(fd,Data,BUFFER_SIZE))>0)
    {
        for(i = 0; i < iRet; i++)
        {
            if(Data[i] == ch)
            {
                iCount++;
            }
        }
    }
    close(fd);
    return iCount;
}
int main()
{
    char FileName[30];
    char cValue;
    int iRet = 0;

    printf("Enter file name :");
    scanf("%s",FileName);

    printf("Enter the character :");
    scanf(" %c",&cValue);

    iRet = CountChar(FileName,cValue);

    printf("Frequency of %c is %d\n",cValue,iRet);
    return 0;
}