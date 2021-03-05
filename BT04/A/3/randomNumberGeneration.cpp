#include<bits/stdc++.h>

using namespace std;

void randomNumberGeneration()
{
    string s;
    cout<<"Enter the file name to create: ";
    cin>>s;
    ofstream f(s);
    int n,x;
    cout<<"Enter n: ";
    cin>>n;
    cout<<endl<<"Enter x: ";
    cin>>x;
    f<<x<<" "<<n;
    f<<endl;
    for(int i=0;i<n;i++)
    {
        f<<rand()<<" ";
    }
};
