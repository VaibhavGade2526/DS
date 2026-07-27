// write a recurisve program which accept number from user and display below pattern

// Input - 5
// 5  *  4  *  3  *  2  *  1

#include<stdio.h>

void Display(int iNo)
{
    if(iNo < 1)
    return;
    printf("%d * ",iNo);

    Display(iNo-1);
}
int main()
{
    Display(5);
    return 0;
}