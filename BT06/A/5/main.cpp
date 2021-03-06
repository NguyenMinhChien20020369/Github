#include <bits/stdc++.h>

using namespace std;

long F(int n) {
   if (n == 0) return 0;
   if (n == 1) return 1;
   return F(n-1) + F(n-2);
}

long myF(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    long sum=0,f=1,a;
    for(int i=1;i<n;i++)
    {
        a=f;
        f=sum+f;
        sum=a;
    }
    return f;
}

int main()
{
    int n;
    //cin>>n;
    //cout<<F(50);//-298632863; 82.850 s
    cout<<myF(50);//-298632863; 1.044 s
    return 0;
}
