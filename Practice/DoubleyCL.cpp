#include<iostream>

using namespace std;

struct node 
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node *PNODE;

class DoubleyCL
{
    private:
       PNODE first;
       PNODE last;
       int  iCount;

       public:
          DoubleyCL();
          void Display();
          int Count();
          void InsertFirst(int iNo);
          void InsertLast(int iNo);
          void InsertAtPos(int iNo,int iPos);

          void DeleteFirst();
          void DeleteLast();
          void DeleteAtPos(int iPos);

};

 DoubleyCL:: DoubleyCL()
 {
     first = NULL;
     last = NULL;
    iCount = 0;
 }
void DoubleyCL:: Display()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
     PNODE temp = NULL;

     temp = first;

     do
     {
        cout<<"|"<<temp->data<<"| <=>";
        temp = temp->next;
     } while (temp != first);
     cout<<"\n";
     
}
int DoubleyCL::Count()
{
 return iCount;
}
void DoubleyCL:: InsertFirst(int iNo)
{
  PNODE newn = NULL;
  newn = new NODE;
  newn->data = iNo;
  newn->next = NULL;
  newn->prev = NULL;

  if(first == NULL)
  {
    first = newn;
    last = newn;
  }
  else
  {
   newn->next = first;
   first->prev = newn;
   first = newn;
  }
   last->next = first;
    first->prev = last;

    iCount++;
}
void DoubleyCL:: InsertLast(int iNo)
{
PNODE newn = NULL;
PNODE temp = NULL;
 newn = new NODE;
  newn->data = iNo;
  newn->next = NULL;
  newn->prev = NULL;

  if(first == NULL)
  {
    first = newn;
    last = newn;
  }
  else
  {
   last->next = newn;
   newn->prev = last;
   last = newn;
  }
   last->next = first;
    first->prev = last;

    iCount++;
}
void DoubleyCL:: InsertAtPos(int iNo,int iPos)
{
 int i = 0;
 PNODE newn = NULL;
 PNODE temp = NULL;

 if((iPos<1)||(iPos>iCount+1))
 {
    cout<<"Invalid postion\n";
    return;
 }

 if(iPos == 1)
 {
    InsertFirst(iNo);
 }
 else if(iPos == iCount+1)
 {
    InsertLast(iNo);
 }
 else
 {
    newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;
    temp = first;
    for(i = 1; i < iPos -1; i++)
    {
        temp = temp->next;
    }

    newn->next = temp->next;
    newn->prev = temp;

    temp->next->prev = newn;
    temp->next = newn;

    iCount++;
 }


}

void DoubleyCL:: DeleteFirst()
{
    PNODE temp = NULL;
  if(first == NULL && last == NULL)
  {
    return;
  }
  else if(first == last)
  {
    delete first;
    first = NULL;
    last = NULL;
  }
  else
  {
      temp = first;

      first = first->next;
      delete temp;

      first->prev = last;
      last->next = first;
  }
  iCount--;
}
void DoubleyCL:: DeleteLast()
{
 PNODE temp = NULL;
  if(first == NULL && last == NULL)
  {
    return;
  }
  else if(first == last)
  {
    delete first;
    first = NULL;
    last = NULL;
  }
  else
  {
      temp = last;

      last = last->prev;
      delete temp;

      last->next = first;
      first->prev = last;
  }
  iCount--;
}
void DoubleyCL:: DeleteAtPos(int iPos)
{
 int i = 0;
 PNODE target = NULL;
 PNODE temp = NULL;

 if((iPos<1)||(iPos>iCount))
 {
    cout<<"Invalid postion\n";
    return;
 }

 if(iPos == 1)
 {
   DeleteFirst();
 }
 else if(iPos == iCount)
 {
    DeleteLast();
 }
 else
 {
    temp = first;
    for(i = 1; i < iPos -1; i++)
    {
        temp = temp->next;
    }

    target = temp->next;

    temp->next = target->next;
    target->next->prev = temp;

    delete target;

    iCount--;
 }
}
int main()
{
    DoubleyCL dobj;
    int iRet = 0;

    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);
    iRet = dobj.Count();
    dobj.Display();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    dobj.InsertLast(101);
    dobj.InsertLast(111);
    dobj.InsertLast(121);
    iRet = dobj.Count();
    dobj.Display();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    dobj.DeleteFirst();
    iRet = dobj.Count();
    dobj.Display();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    dobj.DeleteLast();
    iRet = dobj.Count();
    dobj.Display();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    dobj.InsertAtPos(105,4);
    iRet = dobj.Count();
    dobj.Display();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    dobj.DeleteAtPos(4);
    iRet = dobj.Count();
    dobj.Display();
    cout<<"Number of nodes are :"<<iRet<<"\n";
    
    return 0;
}