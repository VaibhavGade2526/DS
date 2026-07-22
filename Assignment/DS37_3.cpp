// Generic program to Accept N values from user and return addtion of that values
#include<iostream>

using namespace std;

template <class T>
T Add(T *arr, int iSize)
{
    T iSum = 0 ;
    int i = 0;
    for(int i = 0; i < iSize; i++)
    {
        iSum =  iSum + arr[i];
    }
    return iSum;

}

int main()
{
    int Arr[] = {10,20,30,40,50};
    float Brr[] = {10.0f,7.9f,12.4f,11.2f};

    int iSum = Add(Arr,5);
    printf("%d\n",iSum);

    float fSum = Add(Brr,4);
     printf("%d\n",iSum);
    return 0;
}