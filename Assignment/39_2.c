// write a recursive program which display below pattern
// 1  2  3  4  5
#include<stdio.h>

void Display(int iNo)
{
    if(iNo > 5)
    return;
    printf("%d ",iNo);

    Display(iNo+1);

}
int main()
{
Display(1);

    return 0;
}