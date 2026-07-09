// Assignment DS 35 :- Q2
// Count Even Number
// Cout nodes contanining even values
// int CountEven(PNODE Head)


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

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("|%d|->",first->data);
        first = first->next;
    }
    printf("NULL\n");

}
int CountEven(PNODE first)
{
   int iCount = 0;
    while(first != NULL)
    {
        if((first->data %2) == 0 )
        {
            iCount++;
        }
        first = first->next;
    }
    return iCount;
}
void InsertLast(PPNODE first , int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

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

        temp->next= newn;
    }
}
int main()
{
    PNODE head =  NULL;
    int iValue = 0;
    int iRet = 0;

    InsertLast(&head,10);
    InsertLast(&head,11);
    InsertLast(&head,12);
    InsertLast(&head,13);
    InsertLast(&head,14);

    printf("Linked list is :\n");

    Display(head);

    iRet = CountEven(head);

    printf("Number of Even Elements is %d\n",iRet);

    return 0;
}