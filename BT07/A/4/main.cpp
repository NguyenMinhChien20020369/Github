#include <iostream>

using namespace std;

void mySort(int* arr, int arrSize)
{
    int a, last=arrSize-1;
    bool change=true;
    while(change)
    {
        change=false;
        for(int i=0; i<=last; ++i)
        {
            if(*(arr+i)>*(arr+i+1))
            {
                a=*(arr+i);
                *(arr+i)=*(arr+i+1);
                *(arr+i+1)=a;
                change=true;
            }
        }
        --last;
    }
}

bool myFind(const int& numToFind, int* arr, int arrSize)
{
    int first= 0, last= arrSize-1, mid;
    mySort(arr, arrSize);
    while(true)
    {
        mid=(first+last)/2;
        if(numToFind<*(arr+mid))
        {
            last=mid;
        }else if(numToFind>*(arr+mid))
        {
            first=mid;
        }else
        {
            return true;
        }
        if(first+1==last)
        {
            if(*(arr+first)==numToFind||*(arr+last)==numToFind)
            {
                return true;
            }else
            {
                return false;
            }
        }
    }
}

int main()
{
    int arr[10]= {9,7,3,4,8,6,2,5,0,1};
    cout<<myFind(100, arr, 10);
    return 0;
}
