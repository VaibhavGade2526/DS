#include<iostream>

using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;

class CirculerLL
{
    private:
    PNODE first;
    PNODE last;
    int iCount;

    public:
    CirculerLL();
    void Display();
    int Count();
    void InsertFirst(int iNo);
    void InsertLast(int iNo);
    void InsertAtPos(int iNo,int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
};

CirculerLL :: CirculerLL()
{
   first = NULL;
   last = NULL;
   iCount = 0;
}

void CirculerLL :: Display()
{
    PNODE temp  = NULL;
    temp = first;
  if(first == NULL && last == NULL)
  {
    return;
  }

  do
  {
    cout<<"|"<<temp->data<<"| ->";
    temp = temp->next;
  } while (temp != last->next);
  cout<<"\n";
}
int CirculerLL :: Count()
{
 return iCount;
}
void CirculerLL :: InsertFirst(int iNo)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;


    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    last->next = first;
    iCount++;
}
void CirculerLL :: InsertLast(int iNo)
{
 PNODE newn = NULL;
    newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;


    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        last = newn;
    }
    last->next = first;
    iCount++;
}
void CirculerLL :: InsertAtPos(int iNo,int iPos)
{
 int i = 0;
 PNODE newn = NULL;
 PNODE temp = NULL;

 if((iPos < 1)|| (iPos > iCount+1))
 {
    cout<<"Invadlid Position\n";
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

      temp = first;
    for(i = 1; i< iPos-1; i++)
    {
        temp = temp->next;
    }

    newn->next = temp->next;
    temp->next = newn;

    iCount++;
 }
}

void CirculerLL :: DeleteFirst()
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

       last->next = first;
    }
    iCount--;
    
}
void CirculerLL :: DeleteLast()
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

       while(temp->next != last)
       {
        temp = temp->next;
       }
       delete last;
       last = temp;
       last->next = first;
    }
    iCount--;
}
void CirculerLL :: DeleteAtPos(int iPos)
{
  int i = 0;
 PNODE temp = NULL;
 PNODE target = NULL;

 if((iPos < 1)|| (iPos > iCount))
 {
    cout<<"Invadlid Position\n";
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
    for(i = 1; i< iPos-1; i++)
    {
        temp = temp->next;
    }

    target  = temp->next;
    temp->next = target->next;

    delete target;

    iCount--;
 }
}
int main()
{
    int iRet = 0;
    CirculerLL cobj;


    cobj.InsertFirst(51);
    cobj.InsertFirst(21);
    cobj.InsertFirst(11);
    cobj.Display();
    iRet = cobj.Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    cobj.InsertLast(101);
    cobj.InsertLast(111);
    cobj.InsertLast(121);
    cobj.Display();
    iRet = cobj.Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    cobj.DeleteFirst();
    cobj.Display();
    iRet = cobj.Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    cobj.DeleteLast();
    cobj.Display();
    iRet = cobj.Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    cobj.InsertAtPos(105,4);
    cobj.Display();
    iRet = cobj.Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    cobj.DeleteAtPos(4);
    cobj.Display();
    iRet = cobj.Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";
     return 0;
    
}