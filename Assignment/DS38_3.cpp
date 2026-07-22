// write generic program to accept N Vales and search first occurence of any specfic value

#include<iostream>

using namespace std;

template <class T>
T SearchFirst(T *arr, int iSize, T iNo)
{
    int i = 0;
    for ( i = 0; i < iSize; i++)
    {
       if(arr[i] == iNo)
       {
          return i+1;
       }
    }
    return -1;
}
int main()
{
    int Arr[] = {10,20,30,40,50,40,50};

    int iRet = SearchFirst(Arr,7,50);

    printf("%d\n",iRet);

    return 0;
}