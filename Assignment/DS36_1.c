// Assignment DS 36 :- Q1
// Display Odd Elements
// print nodes  only odd values


#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InserLast(PPNODE first,int iNo)
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
        printf("| %d | ->",first->data);
        first = first->next;
    }
    printf("NULL\n");
}

void DisplayOdd(PNODE first)
{
    while(first != NULL)
    {
        if( first->data %2 != 0)
        {
        printf("| %d |->",first->data);
        }
         first = first->next;
    }
    printf("NULL\n");
}
int main()
{
    PNODE head = NULL;

    InserLast(&head,21);
    InserLast(&head,22);
    InserLast(&head,25);
    InserLast(&head,23);
    InserLast(&head,12);
    InserLast(&head,25);


    printf("Linked list is \n");
    Display(head);

    printf("Odd Number are :\n");
    DisplayOdd(head);


    return 0;
}