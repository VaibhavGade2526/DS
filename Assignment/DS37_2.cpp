// Genric program to find largest number from three numbers
#include<iostream>

using namespace std;

template <class T>
T Max(T iNo1, T iNo2,T iNo3)
{
    if(iNo1 > iNo2)
    {
        return iNo1;
    }
    else if (iNo2 > iNo3)
    {
        return iNo2;
    }
    else
    {
        return iNo3;
    }
}
int main()
{
    int iRet = Max(10,20,30);
    printf("Max Number is :%d\n",iRet);

    float fRet = Max(10.2f,20.4f,30.2f);
     printf("Max Number is :%d\n",iRet);
    return 0;

}