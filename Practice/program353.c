#include<stdio.h>

#pragma packe(1)
struct node
{
    int data;
    struct node *next;

};
int main()
{
    struct node obj;

    obj.data = 11;
    obj.next = NULL;


    printf("%lu\n",obj.data);  // 12
     // 4(int) + 8(pointer)

    return 0;
}