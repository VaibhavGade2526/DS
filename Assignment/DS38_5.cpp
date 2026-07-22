// write generic program to accept N values and reverse the contents

#include<iostream>

using namespace std;

template <class T>
void Reverse(T *arr ,int iSize)
{
    int iStart = 0;
    int end = iSize-1;

    while (iStart < end)
    {
       T temp = arr[iStart];
       arr[iStart] = arr[end];
       arr[end] = temp;

       iStart++;
       end--;
    }
    
}
int main()
{
    int Arr[] = {10,20,30,40,50,60,70,80};

    Reverse(Arr,8);

    int i = 0;
    for(i = 0; i<8; i++)
    {
        printf("%d\t",Arr[i]);
    }



    return 0;
}