#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<(n*2-1-((i+1)*2-1))/2;j++){
            cout<<" ";
        }
        for(int j=0;j<(i+1)*2-1;j++){
            cout<<"*";
        }
        for(int j=0;j<(n*2-1-((i+1)*2-1))/2;j++){
            cout<<" ";
        }
        cout<<endl;
    }
}


