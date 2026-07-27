// write a recursive program which accept stirng from user and count number of small character

#include<stdio.h>

int Small(char *str)
{
    if(*str == '\0')
    {
        return 0;
    }
    if(*str >= 'a' && *str <= 'z')
    {
        return 1 + Small(str+1);
    }
   return Small(str+1);
}
int main()
{
    char arr[100];
    int iRet = 0;

    printf("Enter String :");
    scanf("%[^\n]s",arr);
    
    iRet = Small(arr);

    printf("small Cahracter is : %d",iRet);


    return 0;
}