#include<bits/stdc++.h>
#include "myFind.h"
using namespace std;

void bubbleSort()
{
    string s;
    cout<<"Enter the file name: ";
    cin>>s;
    ifstream f(s);
    int n,x;
    f>>n>>x;
    int a[n];
    for(int i=0;i<n;i++)
    {
        f>>a[i];
    }
    f.close();
    bool flag=1,check=1;
    for(int j=n-1;flag;j--){
        flag=0;
        for(int i=0;i<j;i++)
        {
            if(a[i]>a[i+1]){
                int c=a[i];a[i]=a[i+1];a[i+1]=c;
                flag=1;
            }
        }
    }
    cout<<endl;
    for(int i=0;i<n-1;i++)
    {
        if(a[i]>a[i+1]){check=0;}
    }
    if(check){cout<<"Correct"<<endl;}else cout<<"Not correct"<<endl;
    myFind(a,n,x);
};
