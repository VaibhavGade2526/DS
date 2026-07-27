// write a recursive program which display bellow pattern 
// *  *  *  *  *

#include<stdio.h>

void Display(int iNo)
{
    if(iNo > 5)
    return;
        printf("*\t");
    Display(iNo+1);
}
int main()
{
    Display(1);

    return 0;
}