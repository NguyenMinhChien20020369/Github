#include <iostream>

using namespace std;

void f(int a[10])
{
    cout<<"in "<<sizeof(a)/sizeof(a[0])<<endl;
};

int main()
{
    int a[10];
    cout<<"out "<<sizeof(a)/sizeof(a[0])<<endl;
    f(a);
    return 0;
}
