#include <iostream>

using namespace std;

int f(int n)
{
    int a[10000];
    if(n==1)return 0;
    return f(n-1);
}

int main()
{
    int n;
    cin>>n;
    f(n);
    return 0;
    //52
}
