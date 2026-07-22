#include<stdio.h>

#pragma packe(1)
struct node
{
    int data;
    struct node *next;

};
typedef struct node NODE;
typedef struct node *PNODE; 

int main()
{
    PNODE head = NULL;
    PNODE temp = NULL;

    NODE  obj1,obj2,obj3;

    head = &obj1;
    
    obj1.data = 11;
    obj1.next = &obj2;

    obj2.data = 21;
    obj2.next = &obj3;

    obj3.data = 51;
    obj3.next = NULL;

    temp = head;   // 100

    // Sequence 
    
    printf("%u\n",temp->data); //  11

    temp = temp->next;         // 200
    printf("%u\n",temp->data); //  21

    temp = temp->next;         // 300
    printf("%u\n",temp->data); //  51

    temp = temp->next;  // NULL

    return 0;
}