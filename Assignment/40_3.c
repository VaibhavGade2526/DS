// write a recurisve program which accept string from user and count number of character
// Hello
//5

#include<stdio.h>

int Strlen(char *str)
{

  if(*str == '\0')
{
    return 0;
}
return 1 + Strlen(str +1);


}
int main()
{
    int iRet = 0;
    char Arr[20];
    
    printf("Enter String ");
    scanf("%s",Arr);

    iRet = Strlen(Arr);

    printf("%d",iRet);

    return 0;
}