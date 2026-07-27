// Write a recurisive program which accept number from user and return its product of digits

#include<stdio.h>

int Mult(int iNo)
{
    if(iNo == 0 )
    {
        return 1;
    }
    return (iNo % 10)*Mult(iNo/10);
}

int main()
{
    int iValue = 0,iRet = 0;

    printf("Enter Number :");
    scanf("%d",&iValue);

    iRet = Mult(iValue);

    printf("Product of Digits = %d",iRet);

    return 0;
}