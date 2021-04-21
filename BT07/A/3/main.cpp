#include <iostream>

using namespace std;

int count_even(int* arr, int arrSize)
{
    int count_;
    for( int i= 0; i< arrSize; ++i)
    {
        if(arr[i]%2==0)
        {
            ++count_;
        }
    }
    return count_;
}

int main()
{
    //int arr[7]= {2,4,6,8,10,9,7};
    int arr[7]= {9,7,2,4,6,8,10};
    cout<< count_even(arr, 7);
    return 0;
}
