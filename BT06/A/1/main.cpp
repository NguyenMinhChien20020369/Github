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
    // Truyền theo cơ chế con trỏ kiểu tham biến.
    return 0;
}
