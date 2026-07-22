// Generic program Multiplay two  numbers
#include<iostream>

using namespace std;

template <class  T>

T MultiPlay( T iNo1, T iNo2)
{
    T iAns = 0;
    iAns = iNo1 * iNo2;
    return iAns;
}
int main()
{
    int iRet = MultiPlay(10,20);
    printf("%d\n",iRet);

     float fRet = MultiPlay(10.0f,20.0f);
    printf("%f",fRet);

    return 0;
}