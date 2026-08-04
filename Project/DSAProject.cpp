//////////////////////////////////////////////////////////////////////////////////////
//  
// Titel       :-  DSA Implementation Library
//
// Description :- Developed a C Application to implement core data structures incliding
//                Linked Lists,Stack, and Queue The project demonstates basic operations
//                and showcases practical applications of DSA concepts in software development.
//
// Author      :-  Vaibhav Ravindra Gade
// Date        :-  04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////
// 
//    Header Files Inclusion 
//
//////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- Singly Linke List
// Description   :- Implementation of Singly Linked List with 
//                  Insert,Delete, Count,and Display Operations 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////
// 
//   Structure Name :- node
//   Description    :- Repersents a node of a singly Linked List Each node stores
//                     data  and the addres of the next node in the list
//////////////////////////////////////////////////////////////////////////////////////

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

//////////////////////////////////////////////////////////////////////////////////////
// 
//   Typedef Name :- NODE PNODE PPNODE
//   Description  :- Alias for struct node, Pointer to NODE Pointer to Pointer of NODE
//
//////////////////////////////////////////////////////////////////////////////////////

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- Display()
// Description   :- Displays all nodes of the Linked List. 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////

void Display( PNODE first)
{
    while(first != NULL)
    {
        printf("| %d ->",first->data);
        first = first->next;
    }
    printf("NULL\n");
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- Count()
// Description   :- Count the total number nodes in the Linked List. 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////

int Count(PNODE first)
{
    int iCount = 0;

    while (first != NULL)
    {
        iCount++;
        first = first->next;
    }
    return iCount;
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :-InsertFirst()
// Description   :- Insert a new node at the beginning of the linked list 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////

void InsertFirst(PPNODE first,int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;

    if(*first == NULL)   // LL is empty
    {
        *first = newn;
    }
    else 
    {
        newn->next = *first;
        *first = newn;
    }
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :-InsertLast()
// Description   :- Insert a new node at the end of the linked list 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////

void InsertLast(PPNODE first,int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;

    if(*first == NULL) // LL is empty
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

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :-InsertAtPos()
// Description   :- Insert a new node at the specified position 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////

void InsertAtPos(PPNODE first,int iNo,int iPos)
{
    int i = 0;
    int iCount = 0;

    PNODE newn = NULL;
    PNODE temp = NULL;

    iCount = Count(*first);

    if((iPos < 1)||(iPos > iCount+1))
    {
        printf("Invalid postion");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(first ,iNo);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(first , iNo);
    }
    else
    {
       newn = (PNODE)malloc(sizeof(NODE));

      newn->data = iNo;
      newn->next = NULL;

      temp = *first;

      for(i = 1; i < iPos-1; i++)
      {
        temp = temp->next;
      }
      newn->next = temp->next;
      temp->next = newn;
    } 
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- DeleteFirst()
// Description   :- Delete the first node from the linked list 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////

void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;

        *first = (*first)->next;
        free(temp);
    }
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- DeleteLast()
// Description   :- Delete the Last node from the linked list 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////

void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
        
    }
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- DeleteAtPos()
// Description   :- Delete the Last node from the linked list 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////

void DeleteAtPos(PPNODE first,int iPos)
{
    int i = 0;
    int iCount = 0;

    PNODE temp = NULL;
    PNODE target = NULL;

    iCount = Count(*first);

    if((iPos < 1)||(iPos > iCount))
    {
        printf("Invalid postion");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(first);
    }
    else if(iPos == iCount)
    {
        DeleteLast(first);
    }
    else
    {
      temp = *first;

      for(i = 1; i < iPos-1; i++)
      {
        temp = temp->next;
      }
      target = temp->next;

      temp->next = target->next;
      free(target);
    } 
}


//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- Doubley LinkeList
// Description   :- Implementation of Singly Linked List with 
//                  Insert,Delete, Count,and Display Operations 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////
// 
//   Structure Name :- node
//   Description    :- Repersents a node of a Doubly Linked List Each node stores
//                     data  and the addres of the next node in the list
//////////////////////////////////////////////////////////////////////////////////////
/*
struct node
{
    int data;
    struct node *next;
    struct node *prev;  // $
};
*/
//////////////////////////////////////////////////////////////////////////////////////
// 
//   Typedef Name :- NODE PNODE PPNODE
//   Description  :- Alias for struct node, Pointer to NODE Pointer to Pointer of NODE
//
//////////////////////////////////////////////////////////////////////////////////////
/*
typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;
*/
//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- Display1()
// Description   :- Displays all nodes of the doubly Linked List. 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////

void Display1( PNODE first)
{
    printf("\nNULL<=>");
    while(first != NULL)
    {
        printf("| %d <=>",first->data);
        first = first->next;
    }
    printf("NULL\n");
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- Count1()
// Description   :- Count the total number nodes in the doubly Linked List. 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////

int Count1(PNODE first)
{
    int iCount = 0;

    while (first != NULL)
    {
        iCount++;
        first = first->next;
    }
    return iCount;
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :-InsertFirst1()
// Description   :- Insert a new node at the beginning of the doubly linked list 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////

void InsertFirst1(PPNODE first,int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL; // $

    if(*first == NULL)  
    {
        *first = newn;
    }
    else 
    {
        newn->next = *first;
        (*first)->prev = newn;  // $
        *first = newn;
    }
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :-InsertLast1()
// Description   :- Insert a new node at the end of the doubly linked list 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////

void InsertLast1(PPNODE first,int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;  // $

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
        newn->prev = temp; // $
    }
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :-InsertAtPos1()
// Description   :- Insert a new node at the specified position 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////

void InsertAtPos1(PPNODE first,int iNo,int iPos)
{
    int i = 0;
    int iCount = 0;

    PNODE newn = NULL;
    PNODE temp = NULL;

    iCount = Count1(*first);

    if((iPos < 1)||(iPos > iCount+1))
    {
        printf("Invalid postion");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst1(first ,iNo);
    }
    else if(iPos == iCount+1)
    {
        InsertLast1(first , iNo);
    }
    else
    {
       newn = (PNODE)malloc(sizeof(NODE));

      newn->data = iNo;
      newn->next = NULL;
      newn->prev = NULL;  // $

      temp = *first;

      for(i = 1; i < iPos-1; i++)
      {
        temp = temp->next;
      }
      newn->next = temp->next;
      temp->next->prev = newn;  // $
      temp->next = newn;
      newn->prev = temp;  // $
    
    } 
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- DeleteFirst1()
// Description   :- Delete the first node from the doubly linked list 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////
void DeleteFirst1(PPNODE first)
{
    if(*first == NULL)
    {
        return;
    }
    else if((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        *first = (*first)->next;
        free((*first)->prev);  // $
        (*first)->prev = NULL; // $
    }
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- DeleteLast1()
// Description   :- Delete the Last node from the doubly linked list 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////

void DeleteLast1(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);

        temp->next = NULL;
        
    }
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- DeleteAtPos1()
// Description   :- Delete the Last node from the  doubly linked list 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////

void DeleteAtPos1(PPNODE first,int iPos)
{
    int i = 0;
    int iCount = 0;

    PNODE temp = NULL;

    iCount = Count1(*first);

    if((iPos < 1)||(iPos > iCount))
    {
        printf("Invalid postion");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst1(first);
    }
    else if(iPos == iCount)
    {
        DeleteLast1(first);
    }
    else
    {
      temp = *first;

      for(i = 1; i < iPos-1; i++)
      {
        temp = temp->next;
      }
      temp->next = temp->next->next;
      free(temp->next->prev);  // $
      temp->next->prev = temp; // $
    } 
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- Circular Singly Linked List
// Description   :- Implementation of  Circuler Singly Linked List with 
//                  Insert,Delete, Count,and Display Operations 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- Display2()
// Description   :- Displays all nodes of the Circuler Linked List. 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////

void Display2( PNODE first, PNODE last)
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    do
    {
        printf("| %d |->",first->data);
        first = first->next;
    } while (first != last->next);
    printf("\n");
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- Count2()
// Description   :- Count the total number nodes in the Circuler Linked List. 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////

int Count2(PNODE first,PNODE last)
{
    int iCount = 0;

    if(first == NULL && last == NULL)
    {
        return iCount;
    }
    do
    {
        iCount++;
        first = first->next;
    } while (first != last->next);
    
    return iCount;
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :-InsertFirst2()
// Description   :- Insert a new node at the beginning of the Circuler linked list 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////

void InsertFirst2(PPNODE first,PPNODE last,int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;

    if(*first == NULL && *last == NULL)   
    {
        *first = newn;
        *last = newn;
    }
    else 
    {
        newn->next = *first;
        *first = newn;
    }
    (*last)->next = *first;
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :-InsertLast2()
// Description   :- Insert a new node at the end of the  Circuler singly linked list 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////

void InsertLast2(PPNODE first,PPNODE last,int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;

    if(*first == NULL && *last == NULL) 
    {
        *first = newn;
        *last = newn;
    }
    else 
    {
        (*last)->next = newn;
        (*last) = (*last)->next;
    }
    (*last)->next = *first;
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :-InsertAtPos2()
// Description   :- Insert a new node at the specified position 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////

void InsertAtPos2(PPNODE first,PPNODE last,int iNo,int iPos)
{
    int i = 0;
    int iCount = 0;

    PNODE newn = NULL;
    PNODE temp = NULL;

    iCount = Count2(*first,*last);

    if((iPos < 1)||(iPos > iCount+1))
    {
        printf("Invalid postion");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst2(first ,last,iNo);
    }
    else if(iPos == iCount+1)
    {
        InsertLast2(first ,last, iNo);
    }
    else
    {
       newn = (PNODE)malloc(sizeof(NODE));

      newn->data = iNo;
      newn->next = NULL;

      temp = *first;

      for(i = 1; i < iPos-1; i++)
      {
        temp = temp->next;
      }
      newn->next = temp->next;
      temp->next = newn;
    } 
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- DeleteFirst2()
// Description   :- Delete the first node from the linked list 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////

void DeleteFirst2(PPNODE first,PPNODE last)
{
    if(*first == NULL && *last == NULL)
    {
        return;
    }
    else if(*first == *last)
    {
        free(*first);

        *first = NULL;
        *last = NULL;
    }
    else
    {
        *first = (*first)->next;
        free((*last)->next);  // change

        (*last)->next = *first;
    }
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- DeleteLast2()
// Description   :- Delete the Last node from the linked list 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////

void DeleteLast2(PPNODE first,PPNODE last)
{
    PNODE temp = NULL;

    if(*first == NULL && *last == NULL)
    {
        return;
    }
    else if(*first == *last)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        temp = *first;
        while (temp->next != *last)
        {
            temp = temp->next;
        }
        free(*last);  // free(temp->next);
        *last = temp;
        
        (*last)->next = *first;
    }
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- DeleteAtPos2()
// Description   :- Delete the Last node from the linked list 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////

void DeleteAtPos2(PPNODE first,PPNODE last ,int iPos)
{
    int i = 0;
    int iCount = 0;

    PNODE temp = NULL;
    PNODE target = NULL;

    iCount = Count2(*first,*last);

    if((iPos < 1)||(iPos > iCount))
    {
        printf("Invalid postion");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst2(first,last);
    }
    else if(iPos == iCount)
    {
        DeleteLast2(first,last);
    }
    else
    {
      temp = *first;

      for(i = 1; i < iPos-1; i++)
      {
        temp = temp->next;
      }
      target = temp->next;

      temp->next = target->next;
      free(target);
    } 
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- Circular Doubly Linked List
// Description   :- Implementation of  Circuler Doubly Linked List with 
//                  Insert,Delete, Count,and Display Operations 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- Display3()
// Description   :- Displays all nodes of the Circuler Linked doubly List. 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////

void Display3( PNODE first, PNODE last)
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    printf("<=>");
    do
    {
        printf("| %d |<=>",first->data);
        first = first->next;
    } while (first != last->next);
    printf("\n");
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- Count3()
// Description   :- Count the total number nodes in the Circuler doubly  Linked List. 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////

int Count3(PNODE first,PNODE last)
{
    int iCount = 0;

    if(first == NULL && last == NULL)
    {
        return iCount;
    }
    do
    {
        iCount++;
        first = first->next;
    } while (first != last->next);
    
    return iCount;
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :-InsertFirst3()
// Description   :- Insert a new node at the beginning of the Circuler doubly linked list 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////

void InsertFirst3(PPNODE first,PPNODE last,int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;  // $

    if(*first == NULL && *last == NULL)   
    {
        *first = newn;
        *last = newn;
    }
    else 
    {
        newn->next = *first;
        (*first)->prev = newn; // $
        *first = newn;
    }
    (*last)->next = *first;
    (*last)->prev = *last; // $
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :-InsertLast3()
// Description   :- Insert a new node at the end of the  Circuler doubly linked list 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////

void InsertLast3(PPNODE first,PPNODE last,int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL; // $

    if(*first == NULL && *last == NULL) 
    {
        *first = newn;
        *last = newn;
    }
    else 
    {
        (*last)->next = newn;
        newn->prev = *last;  // $
        *last = newn;
    }
    (*last)->next = *first;
    (*last)->prev = *last;  // $
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :-InsertAtPos3()
// Description   :- Insert a new node at the specified position 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////

void InsertAtPos3(PPNODE first,PPNODE last,int iNo,int iPos)
{
    int i = 0;
    int iCount = 0;

    PNODE newn = NULL;
    PNODE temp = NULL;

    iCount = Count3(*first,*last);

    if((iPos < 1)||(iPos > iCount+1))
    {
        printf("Invalid postion");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst3(first ,last,iNo);
    }
    else if(iPos == iCount+1)
    {
        InsertLast3(first ,last, iNo);
    }
    else
    {
       newn = (PNODE)malloc(sizeof(NODE));

      newn->data = iNo;
      newn->next = NULL;
      newn->prev = NULL;  // $

      temp = *first;

      for(i = 1; i < iPos-1; i++)
      {
        temp = temp->next;
      }
      newn->next = temp->next;
      temp->next->prev = newn;

      temp->next = newn;
      newn->prev = temp;
    } 
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- DeleteFirst3()
// Description   :- Delete the first node from the Doubly linked list 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////

void DeleteFirst3(PPNODE first,PPNODE last)
{
    if(*first == NULL && *last == NULL)
    {
        return;
    }
    else if(*first == *last)
    {
        free(*first);

        *first = NULL;
        *last = NULL;
    }
    else
    {
        *first = (*first)->next;
        free((*first)->prev); 

        (*last)->next = *first;
        (*first)->prev = *last;
    }
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- DeleteLast3()
// Description   :- Delete the Last node from the doubly circuler linked list 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////

void DeleteLast3(PPNODE first,PPNODE last)
{
    PNODE temp = NULL;
    if(*first == NULL && *last == NULL)
    {
        return;
    }
    else if(*first == *last)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        temp = *last;
        *last = (*last)->prev;
        (*last)->next = *first;
        (*first)->prev = *last;
        free(temp);
    }
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- DeleteAtPos3()
// Description   :- Delete the Last node from the  doubly circuler linked list 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////

void DeleteAtPos3(PPNODE first,PPNODE last ,int iPos)
{
    int i = 0;
    int iCount = 0;

    PNODE temp = NULL;
    PNODE target = NULL;

    iCount = Count3(*first,*last);

    if((iPos < 1)||(iPos > iCount))
    {
        printf("Invalid postion");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst3(first,last);
    }
    else if(iPos == iCount)
    {
        DeleteLast3(first,last);
    }
    else
    {
      temp = *first;

      for(i = 1; i < iPos-1; i++)
      {
        temp = temp->next;
      }
      target = temp->next;
      temp->next = target->next;
      target->next->prev = temp;
      free(target);
    } 
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- Stack
// Description   :- Implementation  of stack using Linkedlist
//                  Push,Pop,Peep, Count,and Display Operations 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- Push()   // InsertFirst
// Description   :- Insert an elements onto the Stack
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////

int iCount = 0;  // for stack

void Push(PPNODE first,int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = *first;
    *first = newn;

    iCount++;
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :-  Pop()  // DeleteFirst()
// Description   :- Remove the top elements from the stack 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////

int Pop(PPNODE first)
{
    int iValue = 0;
    PNODE temp = NULL;

    if(*first == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    iValue = (*first)->data;
    temp = *first;
    *first = (*first)->next;
    free(temp);
    iCount--;

    return iValue;
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- Peep()  // DeleteFirst() 
// Description   :- Returns the top elements without removing it.
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////

int Peep(PNODE first)
{
    if(first == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return first->data;
}
//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- Display4()
// Description   :- Displays all elements of this stack. 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////

void Display4( PNODE first)
{
    while(first != NULL)
    {
        printf("| %d |\n",first->data);
        first = first->next;
    }
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- Count4()
// Description   :- Count the total number of elements 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////

int Count4()
{
    return iCount;
}


//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- Queue 
// Description   :- Implementation of Queue of  using Linkedlist
//                  Enqueue,Dequeue,, Count,and Display Operations 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- Enqueue()   // InsertLast
// Description   :- Insert an elements at the reaer the queue
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////

int iCount1 = 0;// for Queue

void Enqueue(PPNODE first,int iNo)
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
    iCount1++;
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- Dequeue()   // DeleteLast()
// Description   :- Removes and  returns elements of the queue
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////
int Dequeue(PPNODE first)
{
    int iValue = 0;
    PNODE temp = NULL;

    if(*first == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }

    iValue = (*first)->data;
    temp = *first;

    *first = (*first)->next;

    free(temp);
    iCount1--;

    return iValue;
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- Display4()
// Description   :- Displays all elements of this Queue. 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////

void Display5(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d |\n",first->data);
        first = first->next;
    }
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- Count5()
// Description   :- Count the total number of elements 
// Author        :- Vaibhav Ravindra Gade
// Date          :- 04/08/2026
//
//////////////////////////////////////////////////////////////////////////////////////

int Count5()
{
    return iCount1;
}
//////////////////////////////////////////////////////////////////////////////////////
// 
//    Entry Point Function of the DSA Project 
//
//////////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE head = NULL;   //Singly LL
    PNODE head1 = NULL; // Doubly LL
    PNODE head2 = NULL; // Circuler LL
    PNODE tail = NULL;  // Circuler LL
    PNODE head3 = NULL; // Circuler Doulyy LL
    PNODE tail1 = NULL; // Circuler Doubly DL
    PNODE head4 = NULL; // Stack
    PNODE head5 = NULL;  // Queue
    int iRet = 0;

    printf("-----------------------------------------------------------------------\n");
    printf("------------------------SINGLY LINEKD LIST----------------------------\n");
    printf("\n----------------------------InsertFirst-----------------------------\n");
    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);
    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n",iRet);

    printf("\n--------------------------InsertLast---------------------------\n");
    InsertLast(&head,101);
    InsertLast(&head,111);
    InsertLast(&head,121);
    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n",iRet);

    printf("\n--------------------------InsertAtPos---------------------------\n");
    InsertAtPos(&head,100,4);
    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n",iRet);

    printf("\n----------------------------DeleteFirst----------------------------\n");
    DeleteFirst(&head);
    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n",iRet);

    printf("\n----------------------------DeleteLast-----------------------------\n");
    DeleteLast(&head);
    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n",iRet);

    printf("\n----------------------------DeleteAtPos----------------------------\n");
    DeleteAtPos(&head,4);
    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n",iRet);
    
    printf("\n-----------------------------------------------------------------------\n");
    printf("--------------------------Doubly LINEKD LIST-----------------------------\n");
    printf("\n------------------------------InsertFirst------------------------------\n");
    InsertFirst1(&head1,30);
    InsertFirst1(&head1,20);
    InsertFirst1(&head1,10);
    Display1(head1);
    iRet = Count1(head1);
    printf("Number of nodes are : %d\n",iRet);

    printf("\n--------------------------InsertLast---------------------------\n");
    InsertLast1(&head1,40);
    InsertLast1(&head1,50);
    InsertLast1(&head1,60);
    Display1(head1);
    iRet = Count1(head1);
    printf("Number of nodes are : %d\n",iRet);

    printf("\n--------------------------InsertAtPos---------------------------\n");
    InsertAtPos1(&head1,100,4);
    Display1(head1);
    iRet = Count1(head1);
    printf("Number of nodes are : %d\n",iRet);

    printf("\n----------------------------DeleteFirst-----------------------------\n");
    DeleteFirst1(&head1);
    Display1(head1);
    iRet = Count1(head1);
    printf("Number of nodes are : %d\n",iRet);

    printf("\n----------------------------DeleteLast-----------------------------\n");
    DeleteLast1(&head1);
    Display1(head1);
    iRet = Count1(head1);
    printf("Number of nodes are : %d\n",iRet);

    printf("\n----------------------------DeleteAtPos-----------------------------\n");
    DeleteAtPos1(&head1,3);
    Display1(head1);
    iRet = Count1(head1);
    printf("Number of nodes are : %d\n",iRet);


    printf("-------------------------------------------------------------------------\n");
    printf("----------------------Circuler Singly LINKED LIST-------------------------\n");
    printf("\n----------------------------InsertFirst---------------------------------\n");
    InsertFirst2(&head2,&tail,3);
    InsertFirst2(&head2,&tail,2);
    InsertFirst2(&head2,&tail,1);
    Display2(head2,tail);
    iRet = Count2(head2,tail);
    printf("Number of nodes are : %d\n",iRet);

    printf("\n--------------------------InsertLast------------------------------\n");
    InsertLast2(&head1,&tail,4);
    InsertLast2(&head1,&tail,5);
    InsertLast2(&head1,&tail,6);
    Display2(head2,tail);
    iRet = Count2(head2,tail);
    printf("Number of nodes are : %d\n",iRet);

    printf("\n--------------------------InsertAtPos-----------------------------\n");
    InsertAtPos2(&head2,&tail,10,4);
    Display2(head2,tail);
    iRet = Count2(head2,tail);
    printf("Number of nodes are : %d\n",iRet);

    printf("\n----------------------------DeleteFirst-----------------------------\n");
    DeleteFirst2(&head2,&tail);
    Display2(head2,tail);
    iRet = Count2(head2,tail);
    printf("Number of nodes are : %d\n",iRet);

    printf("\n------------------------------DeleteLast---------------------------------\n");
    DeleteLast2(&head2,&tail);
    Display2(head2,tail);
    iRet = Count2(head2,tail);
    printf("Number of nodes are : %d\n",iRet);

    printf("\n------------------------------DeleteAtPos-------------------------------\n");
    DeleteAtPos2(&head2,&tail,3);
    Display2(head2,tail);
    iRet = Count2(head2,tail);
    printf("Number of nodes are : %d\n",iRet);

    printf("--------------------------------------------------------------------------\n");
    printf("----------------------Circuler Doubly LINKED LIST-------------------------\n");
    printf("\n-----------------------------InsertFirst--------------------------------\n");
    InsertFirst3(&head3,&tail1,300);
     InsertFirst3(&head3,&tail1,200);
     InsertFirst3(&head3,&tail1,100);
    Display3(head3,tail1);
    iRet = Count3(head3,tail1);
    printf("Number of nodes are : %d\n",iRet);

    printf("\n------------------------------InsertLast-----------------------------\n");
    InsertLast3(&head3,&tail1,400);
    InsertLast3(&head3,&tail1,500);
    InsertLast3(&head3,&tail1,600);
    Display3(head3,tail1);
    iRet = Count3(head3,tail1);
    printf("Number of nodes are : %d\n",iRet);

    printf("\n------------------------------InsertAtPos---------------------------\n");
    InsertAtPos3(&head3,&tail1,550,4);
    Display3(head3,tail1);
    iRet = Count3(head3,tail1);
    printf("Number of nodes are : %d\n",iRet);

    printf("\n----------------------------DeleteFirst-----------------------------\n");
    DeleteFirst3(&head3,&tail1);
    Display3(head3,tail1);
    iRet = Count3(head3,tail1);
    printf("Number of nodes are : %d\n",iRet);

    printf("\n----------------------------DeleteLast------------------------------\n");
    DeleteLast3(&head3,&tail1);
    Display3(head3,tail1);
    iRet = Count3(head3,tail1);
    printf("Number of nodes are : %d\n",iRet);

    printf("\n------------------------------DeleteAtPos----------------------------\n");
    DeleteAtPos3(&head3,&tail1,3);
    Display3(head3,tail1);
    iRet = Count3(head3,tail1);
    printf("Number of nodes are : %d\n",iRet);

    printf("----------------------------------------------------------------------\n");
    printf("----------------------------------Stack-------------------------------\n");
    printf("\n--------------------------------Push--------------------------------\n");
    Push(&head4,11);
    Push(&head4,22);
    Push(&head4,33);
    Display4(head4);
    iRet = Count4();
    printf("Elements in stack :%d\n",iRet);

    printf("\n----------------------------Pop-----------------------------\n");
    iRet = Pop(&head4);
    printf("\nPopped Elements  : %d\n",iRet);
    Display4(head4);
    iRet = Count4();
    printf("Elements in stack :%d\n",iRet);

    printf("\n----------------------------Peep-----------------------------\n");
    iRet = Peep(head4);
    printf("\nTop Elements : %d\n",iRet);
    Display4(head4);
    iRet = Count4();
    printf("Elements in stack :%d\n",iRet);

    printf("-----------------------------------------------------------------------\n");
    printf("----------------------------------Queue-------------------------------\n");
    printf("\n------------------------------Enqueue--------------------------------\n");
    Enqueue(&head5,5);
    Enqueue(&head5,10);
    Enqueue(&head5,15);
    Display5(head5);
    iRet = Count5();
    printf("Elements in Queue : %d\n",iRet);

    printf("\n---------------------------------Dequeue-------------------------------\n");
    iRet = Dequeue(&head5);
    printf("\nRemoved Elements : %d\n",iRet);
    Display5(head5);
    iRet = Count5();
    printf("Elements in Queue : %d\n",iRet);


    printf("\n================================================================================\n");
    printf("   DSA PROJECT EXECUTED SUCESSFULLY\n       ");
    printf("    Thank You!\n");
    printf("================================================================================\n");

    return 0;
}
