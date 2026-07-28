//  write a program which accepts file name from user and count number if captial character from that file
#include<stdio.h>
#include<stdlib.h>
#include<io.h>
#include<fcntl.h>
#include<unistd.h>

#define BUFFER_SIZE 1024

int CountCaptial(char FName[])
{
    int fd = 0;
    int iRet = 0, i = 0, iCount = 0;
    char Data[BUFFER_SIZE];

    fd = open(FName,O_RDONLY);

    if(fd == -1)
    {
        printf("unable to open file\n");
        return -1;
    }

    while((iRet = read(fd,Data,BUFFER_SIZE))>0)
    {
        for(i =0; i < iRet; i++)
        {
            if(Data[i] >= 'A' && Data[i] <='Z')
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
    int iRet = 0;

    printf("Enter file name :");
    scanf("%s",FileName);

    iRet = CountCaptial(FileName);

    printf("Number of capital character are %d\n",iRet);
    return 0;
}