// write a recursive program which display below patteren
// 5  4  3  2  1

#include<stdio.h>

void Display(int iNo)
{
    if(iNo < 1)
    return;
    printf("%d\n",iNo);
    Display(iNo - 1);
}
int main()
{
    Display(5);
    return 0;
}