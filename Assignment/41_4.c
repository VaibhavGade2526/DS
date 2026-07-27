// write a recursive program which accept number from user and return smallest digit

#include<stdio.h>

int Small(int iNo)
{
   
    if(iNo < 10)
    {
        return iNo;       
    }
    int iDigit = 0;
       iDigit = iNo%10;

      int min = Small(iNo/10);

       if(iDigit < min)
       {
        return iDigit;
       }
       else
       {
        return min;
       }

}
int main()
{
    int iValue = 0, iRet = 0;

    printf("Enter number :");
    scanf("%d",&iValue);

    iRet = Small(iValue);

    printf("smallest digit is : %d",iRet);
    return 0;
}