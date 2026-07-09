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
        temp-> next =newn;
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
    int Frequency(PNODE first,int iNo)
    {
        int iCount = 0;

        while(first != NULL)
        {
            if(first->data == iNo)
            {
                iCount++;
            }
            first = first->next;
        }

        return iCount;
    }

 int main()
 {
    PNODE head = NULL;
    int iRet = 0;
    int iValue = 0;

    InserLast(&head,11);
    InserLast(&head,20);
    InserLast(&head,12);
    InserLast(&head,21);
    InserLast(&head,52);

    printf("Linked list is :\n");

    Display(head);

    printf("Enter the element to find frequency:");
    scanf("%d",&iValue);

    iRet = Frequency(head,iValue);
  
    printf("Frequency of  %d is %d\n",iRet);

    return 0;
 }