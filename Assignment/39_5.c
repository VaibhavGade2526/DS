//  write a recursive program which display below pattern
//a  b  c  d  e  f

#include<stdio.h>

void Display(char ch)
{
    if(ch>'f')
    return;

    printf("%c\n",ch);
    Display(ch +1);

}
int main()
{
    Display('a');
    return 0;
}