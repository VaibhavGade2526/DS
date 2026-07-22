// Count Number Greater than iNo
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

void InsertFirst(PPNODE first,int iNo)
{
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
        newn->next = *first;
        *first = newn;
    }
}

void Display(PNODE first)
{
    printf("Linked list :");

    while(first != NULL)
    {
       printf("| %d |->",first->data);
       first = first->next;
    }
    printf("\n");
}

int CountGreater(PNODE first,int iNo)
{
    int Count = 0;

    while(first != NULL)
    {
        if(first->data > iNo)
        {
          Count++;
        }
          first = first->next;
    }
    return Count;
}
int main()
{
    PNODE head = NULL;
    int iRet = 0;
    int iValue = 0;

    InsertFirst(&head,60);
    InsertFirst(&head,50);
    InsertFirst(&head,40);
    InsertFirst(&head,30);
    InsertFirst(&head,20);
    InsertFirst(&head,10);

    Display(head);

    printf("Enter value:");
    scanf("%d",&iValue);

    iRet = CountGreater(head,iValue);

    printf("Count of elements greater than %d is :%d\n :",iValue,iRet);
    return 0;
}