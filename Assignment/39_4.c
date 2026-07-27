//  write a recursive program which display below pattern
// A  B  C  D  E  F

#include<stdio.h>

void Display(char ch)
{
    if(ch>'F')
    return;

    printf("%c\n",ch);
    Display(ch +1);

}
int main()
{
    Display('A');
    return 0;
}