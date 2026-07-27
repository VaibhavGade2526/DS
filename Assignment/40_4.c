// wrirte a recurisve program which accept number from user and return its factoral

#include<stdio.h>

int Fact(int iNo)
{
    int fact = 1;

    if(iNo == 0 || iNo == 1)
    {
       return 1;
    } 
    else
    {
        return iNo*Fact(iNo-1);
    }

}
int main()
{
 int iRet = 0;
 int iValue = 0;

 printf("Enter number :");
 scanf("%d",&iValue);

 iRet = Fact(iValue);

 printf("%d",iRet);

    return 0;
}