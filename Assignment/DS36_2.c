// First Occuenece Postion
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

int FirstOccur(PNODE first,int iNo)
{
    int i = 1;

    while(first != NULL)
    {
        if(first->data == iNo)
        {
            return i;
        }
          first = first->next;
            i++;
    }
    return -1;
}
int main()
{
    PNODE head = NULL;
    int iRet = 0;
    int iValue = 0;

    InsertFirst(&head,10);
    InsertFirst(&head,20);
    InsertFirst(&head,30);
    InsertFirst(&head,40);
    InsertFirst(&head,50);
    InsertFirst(&head,60);

    Display(head);

    printf("Enter elements to search :");
    scanf("%d",&iValue);

    iRet = FirstOccur(head,iValue);

    if(iRet == -1)
    {
        printf("Elements not found\n");
    }
    else
    {
        printf("first occurence is at postion : %d\n",iRet);
    }
    return 0;

}