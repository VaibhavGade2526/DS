// write a  recursive program which accept string from user and count white spaces

#include<stdio.h>

int WhiteSpace(char *str)
{
    if(*str == '\0')
    {
       return 0;
    }

    if(*str == ' ')
    {
       return 1 + WhiteSpace(str+1);
    }
    return WhiteSpace(str+1);
}
int main()
{
    char arr[100];

    printf("Enter String :");
    scanf("%[^\n]s",arr);

    printf("white spaces = %d",WhiteSpace(arr));

    return 0;
}