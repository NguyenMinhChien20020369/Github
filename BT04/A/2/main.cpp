#include <bits/stdc++.h>
#include "myFind.h"
#include "randomNumberGeneration.h"

using namespace std;

int main()
{
    //randomNumberGeneration();
    string s;
    cout<<"Enter the file name: ";
    cin>>s;
    ifstream f(s);
    int x,n;
    f>>x>>n;
    int a[n];
    for(int i=0;i<n;i++){
        f>>a[i];
    }
    myFind(a,n,x);
    return 0;
}
