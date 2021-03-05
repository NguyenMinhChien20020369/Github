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
        for(int j=n-1;j!=i&&a[j]>=0;j--){
            if(a[i]+a[j]<=0){
                for(int k=j-1;a[k]>=-a[i]-a[j];k--){
                    if(a[i]+a[j]+a[k]==0){cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<endl;check=1;}
                }
            }else
                for(int k=i+1;a[k]<=-a[i]-a[j];k--){
                    if(a[i]+a[j]+a[k]==0){cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<endl;check=1;}
                }
        }
    }
    if(!check){cout<<"Not Found";}
    return 0;
}
