#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    do{
    cin>>n;if(n==-1){cout<<"Bye"<<endl;break;}
    if(n>=0&&n%5==0)cout<<n/5<<endl;else cout<<-1<<endl;
    }while(true);
}
