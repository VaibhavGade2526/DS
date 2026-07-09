#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;

};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node **PPNODE;

void InsertLast(PPNODE first,int iNo)
{
   PNODE temp = NULL;
   PNODE newn = NULL;

   newn = (PNODE)malloc(sizeof(NODE));

   newn->data = iNo;
   newn->next = NULL;

   if(*first == NULL)
   {
      *first = newn;
   }
   else
   {
    temp = *first;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newn;

   }
}
void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d |->",first->data);
        first = first->next;
    }
    printf("NULL\n");
}
void DisplayEven(PNODE first)
{
    while(first != NULL)
    {
        if(first->data%2 == 0)
        {
            printf("|%d|->",first->data);
        }
        first = first->next;
    }
    printf("NULL\n");
}
int main()
{
    PNODE head = NULL;

    InsertLast(&head,11);
    InsertLast(&head,20);
    InsertLast(&head,21);
    InsertLast(&head,51);
    InsertLast(&head,111);
    InsertLast(&head,80);

    printf("Linked list is :\n");
    Display(head);

    printf("Even elements are :\n");

    DisplayEven(head);

    return 0;
}