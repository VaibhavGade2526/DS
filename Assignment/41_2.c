// write a  recursive program which accept number from user and return largest digit

#include<stdio.h>

int Max(int iNo)
{
    if(iNo < 10)
    {
        return iNo ;
    }
    int iDigit = 0;
    iDigit = iNo%10;
    int max = Max(iNo/10);

    if(iDigit>max)
    {
        return iDigit;
    }
    else
    {
        return max;
    }
}
int main()
{
    int iValue = 0;
    printf("ENter number :");
    scanf("%d",&iValue);

    printf("Largest digit = %d",Max(iValue));

    return 0;
}