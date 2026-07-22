// generic program accept number fo user and display largest number

#include<iostream>

using namespace std;
template <class T>
T Min( T *arr, int iSize)
{
    T Min = arr[0];
    int i = 0;

    for(i = 0; i < iSize; i++)
    {
        if(arr[i] < Min)
        {
            Min = arr[i];
        }
    }
    return Min;
}
int main()
{
    int Arr[] = {10,20,30,40,50};
    float Brr[] = {10.2f,12.2f,12.5f,15.5f,12.4f};

    int iRet = Min(Arr,5);
    printf("Smallest number %d\n:",iRet);

    float fRet = Min(Brr,5);
    printf("Smallest Number %f\n:",fRet);

    return 0;
}