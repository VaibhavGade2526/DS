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

void Display(PNODE first )
{
    while(first != NULL)
    {
        printf("| %d |-> ",first->data);
        first = first ->next;
    }
    printf("NULL\n");
}
int CountOdd(PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        if((first->data%2 != 0))
        {
            iCount++;
        }
        first = first->next;
    }
    return iCount;
}

void InsertLast(PPNODE first,int iNo)
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
         temp->next = newn;
    }
   }


int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertLast(&head,11);
    InsertLast(&head,12);
    InsertLast(&head,13);
    InsertLast(&head,14);
    InsertLast(&head,15);

    Display(head);

    iRet = CountOdd(head);

    printf("Number of odd elements ; %d\n",iRet);

    return 0;
}