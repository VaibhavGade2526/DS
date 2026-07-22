/// write generic program to accept N values and count frequency of any specific value

#include<iostream>

using namespace std;

int Frequency(int *arr, int iSize,int iNo)
{
    int i = 0;
    int iCount = 0;
    for ( i = 0; i < iSize; i++)
    {
        if(arr[i] == iNo)
        {
            iCount++;
        }
    }
    return iCount;
    
}
int main()
{
    int Arr[] = { 10,20,30,40,50,50,60,50};
    int iRet = Frequency(Arr,8,50);
    printf("%d",iRet);

    return 0;
}