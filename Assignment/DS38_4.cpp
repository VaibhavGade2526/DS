// write a generic progrm to accept N values and search last aoocurance of any speicifc value
#include<iostream>

using namespace std;

template <class T>
T SearchLast(T *arr, int iSize,T iNo)
{
    int i =  0;
    for(i = iSize - 1; i >= 0; i--)
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
    int Arr[] = {10,20,30,40,50,60,40,50};

    int iRet = SearchLast(Arr,8,40);

    printf(" last occurrence :%d",iRet);

    return 0;
}