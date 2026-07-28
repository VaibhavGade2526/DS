//  write aprogram which accept file name from user and count number of white spaces from that file

#include<stdio.h>
#include<stdlib.h>
#include<io.h>
#include<fcntl.h>
#include<unistd.h>

#define BUFFER_SIZE 1024

int CountWhiteSpace(char FName[])
{
   int fd = 0;
   int iRet = 0,iCount = 0, i = 0;
    char Data[BUFFER_SIZE];

   fd = open(FName ,O_RDONLY);

   if(fd == -1)
   {
     printf("Unable to open file\n:");
     return -1;
   }
   
   while((iRet = read(fd,Data,BUFFER_SIZE) )>0)
   {
      for(i = 0; i<iRet; i++)
      {
        if(Data[i] == ' ')
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
    char FName[30];
    int iRet = 0;

    printf("Enter file name :");
    scanf("%s",FName);

    iRet = CountWhiteSpace(FName);

    printf("Number of white spaces are : %d\n",iRet);

    return 0;
}