#include <bits/stdc++.h>
#include "randomNumberGeneration.h"
using namespace std;

int main()
{
    //randomNumberGeneration();
    string s;
    cout<<"Enter the test name: ";
    cin>>s;
    ifstream f(s);
    int n;
    f>>n;
    int a[n];
    for(int i=0;i<n;i++){
        f>>a[i];
    }
    sort(a,a+n);
    bool check=0;
    for(int i=0;a[i]<=0;i++){
        for(int j=n-1;j!=i&&a[j]>=0&&a[j]>=abs(a[i]);j--){
            if(a[i]+a[j]==0){cout<<a[i]<<" "<<a[j]<<endl;check=1;}
        }
    }
    if(!check){cout<<"Not Found";}
    return 0;
}
