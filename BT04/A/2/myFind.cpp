#include <bits/stdc++.h>

using namespace std;

void myFind(int* a, int n, int x)
{
    for(int i=0;i<n;i++){
        if(a[i]==x){cout<<"x is a["<<i<<"]";return;}
    }
    cout<<"Couldn't find x";
};
