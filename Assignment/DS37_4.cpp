// generic program accept number fo user and display largest number

#include<iostream>

using namespace std;
template <class T>
T Max( T *arr, int iSize)
{
    T Max = 0;
    int i = 0;

    for(i = 0; i < iSize; i++)
    {
        if(arr[i] > Max)
        {
            Max = arr[i];
        }
    }
    return Max;
}
int main()
{
    int Arr[] = {10,20,30,40,50};
    float Brr[] = {10.2f,12.2f,12.5f,15.5f,12.4f};

    int iRet = Max(Arr,5);
    printf("Largest number %d\n:",iRet);

    float fRet = Max(Brr,5);
    printf("Largest Number %f\n:",fRet);

    return 0;
}