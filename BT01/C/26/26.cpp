#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;double tong=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];tong+=a[i];
    }
    sort(a,a+n);
    tong/=n;
    cout<<"Mean: "<<tong<<endl;
    cout<<"Max: "<<a[n-1]<<endl;
    cout<<"Min: "<<a[0]<<endl;
}
