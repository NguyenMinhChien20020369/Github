#include <iostream>

using namespace std;

void f(int* a)
{
    cout<<&a<<" "<<&a[0];
};

int main()
{
    int a[]={3,7,4};
    cout<<&a<<" "<<&a[0]<<endl;
    f(a);
    return 0;
}
