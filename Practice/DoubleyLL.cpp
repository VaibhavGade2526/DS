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

class DoubleyLL
{
    private:
    PNODE first;
    int iCount ;

    public:
    DoubleyLL();

    void Display();
    int Count();
    void InsertFirst(int iNo);
    void InsertLast(int iNo);
    void InsertAtPos(int iNo,int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);

};

DoubleyLL :: DoubleyLL()
{
    this->first = NULL;
    this->iCount = 0;
}

void DoubleyLL :: Display()
{
  PNODE temp = NULL;
  temp = first;
 
  cout<<"NULL\n"<<endl;

while(temp != NULL)
{
    cout<<"|"<<temp->data<<"| <=> ";
    temp = temp->next;
}
cout<<"NULL\n";
}


int  DoubleyLL ::Count()
{
    return iCount;
}

void DoubleyLL ::InsertFirst(int iNo)
{
    PNODE newn =  NULL;

    newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }
    this->iCount++;
}
void DoubleyLL ::InsertLast(int iNo)
{
  PNODE newn =  NULL;
  PNODE temp = NULL;

    newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    this->iCount++;
}
void DoubleyLL ::InsertAtPos(int iNo,int iPos)
{
  int i =0;
  PNODE newn = NULL;
  PNODE temp = NULL;

  if((iPos<1)||(iPos>iCount+1))
  {
    printf("Invalid postion\n");
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
    temp = first;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    for(i = 1; i < iPos-1; i++)
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

void DoubleyLL ::DeleteFirst()
{
  if(first == NULL)
  {
    return;
  }
  else if(first->next == NULL)
  {
    delete first;
    first = NULL;
  }
  else
  {
      first = first->next;
      delete first->prev;
     first->prev = NULL;
  }
}

void DoubleyLL ::DeleteLast()
{
    PNODE temp = NULL;

    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
       delete first;
       first = NULL;
    }
    else
    {
        temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        delete temp;
    }
    iCount--;
}
 void DoubleyLL :: DeleteAtPos(int iPos)
 {
   int i =0;
  PNODE target = NULL;
  PNODE temp = NULL;

  if((iPos<1)||(iPos>iCount))
  {
    printf("Invalid postion\n");
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
    for(i = 1; i < iPos-1; i++)
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
    DoubleyLL dobj;
    int iRet = 0 ;

    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of elements are :"<<iRet<<endl;

    dobj.InsertLast(101);
    dobj.InsertLast(111);
    dobj.InsertLast(121);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of elements are :"<<iRet<<endl;

    dobj.DeleteFirst();
    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of elements are :"<<iRet<<endl;

    dobj.DeleteLast();
    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of elements are :"<<iRet<<endl;

    dobj.InsertAtPos(105,4);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of elements are :"<<iRet<<endl;

    dobj.DeleteAtPos(4);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of elements are :"<<iRet<<endl;
    return 0;
}