#include<iostream>

using namespace std;

template <class T>
struct node 
{
    int data;
    struct node <T> *next;
    struct node<T> *prev;
};


template <class T>
class DoubleyCL
{
    private:
    struct node<T> *first;
    struct node<T> *last;
       int  iCount;

       public:
          DoubleyCL();
          void Display();
          int Count();
          void InsertFirst(T iNo);
          void InsertLast(T iNo);
          void InsertAtPos(T iNo,int iPos);

          void DeleteFirst();
          void DeleteLast();
          void DeleteAtPos(int iPos);

};

template <class T>
 DoubleyCL<T>:: DoubleyCL()
 {
     first = NULL;
     last = NULL;
    iCount = 0;
 }

template <class T>
void DoubleyCL<T>:: Display()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    struct node<T> *temp = NULL;

     temp = first;

     do
     {
        cout<<"|"<<temp->data<<"| <=>";
        temp = temp->next;
     } while (temp != first);
     cout<<"\n";
     
}

template <class T>
int DoubleyCL<T>::Count()
{
 return iCount;
}

template <class T>
void DoubleyCL<T>:: InsertFirst(T iNo)
{
   struct node<T> * newn = NULL;
  newn = new  struct node<T> ;
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

template <class T>
void DoubleyCL<T>:: InsertLast(T iNo)
{
 struct node<T> *newn = NULL;
 struct node<T> *temp = NULL;
 newn = new struct node<T> ;
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

template <class T>
void DoubleyCL<T>:: InsertAtPos(T iNo,int iPos)
{
 int i = 0;
  struct node<T> * newn = NULL;
 struct node<T> *temp = NULL;

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
    newn = new  struct node<T> ;

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

template <class T>
void DoubleyCL<T>:: DeleteFirst()
{
     struct node<T> *temp = NULL;
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

template <class T>
void DoubleyCL<T>:: DeleteLast()
{
  struct node<T> *temp = NULL;
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

template <class T>
void DoubleyCL<T>:: DeleteAtPos(int iPos)
{
 int i = 0;
 struct node<T> *target = NULL;
 struct node<T> *temp = NULL;

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
    DoubleyCL<int> dobj;
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