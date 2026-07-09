// Assignment DS 35 :- Q1
// ! search an Eleement
// check whether a number is present 
// bool search(PNODE Head, int iNo)


#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct node
{
    int data ;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;



void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d |->",first->data);
        first = first->next;
    }
    printf("NULL\n");
}
void InsertLast(PPNODE first ,int iNo)
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

bool Search(PNODE first ,int iNo)
{
    while(first != NULL)
    {
        if(first->data == iNo)
        {
            return true;
        }
        else
        {
            return false;
        }

        first = first->next;
    }

    return false;
}
int main()
{
    PNODE head = NULL;
    int value = 0;
    bool bRet = false;

    InsertLast(&head,10);
    InsertLast(&head,20);
    InsertLast(&head,30);
    InsertLast(&head,40);
    InsertLast(&head,50);

    printf("Linked list is : \n");
    Display(head);

    printf("Enter number to search :");
    scanf("%d",&value);

    bRet = Search(head,value);

    if(bRet == true)
    {
        printf("Elements is prsent in linked list \n");
    }
    else
    {
        printf("Elements is not prsent in linked list \n");
    }
    return 0;
}