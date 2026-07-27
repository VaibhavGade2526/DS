// write a recursive program which accept number from user and return its reverse number 

#include<stdio.h>

int  Reverse(int iNo)
{
    static int iRev = 0;
    if(iNo == 0)
    {
        return iRev;
    }

    iRev = (iRev * 10) + ( iNo % 10);

    return Reverse(iNo / 10);
}
int main()
{
    int iValue = 0, iRet = 0;

    printf("Enter Number  :");
    scanf("%d",&iValue);

    iRet = Reverse(iValue);

    printf("Reverse number is : %d",iRet);

    return 0;
}