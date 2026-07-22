// write generic program which accept one  value and one number from user print. that value that number of times on screen

#include<iostream>

using namespace std;

template <class T>

void Display(T value, int iSize)
{
    int i =0;
  for(i = 0; i < iSize; i++)
  {
    printf("%d ",value);
  }
  printf("\n");
}
int main()
{
    Display('M',7);
    Display(11,3);
    Display(7.7,5);
    Display(4,7);
    Display('P',7);

    return 0;
}