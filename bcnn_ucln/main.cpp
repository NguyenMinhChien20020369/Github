#include<bits/stdc++.h>
using namespace std;

int bcnn(int a,int b){
    int i=1;
    while(true){
        if((max(a,b)*i)%a==0&&(max(a,b)*i)%b==0){
            break;
        }
        i++;
    }
    return max(a,b)*i;
}

int ucln(int a,int b){
    int c;
    for(int i=min(a,b);i>=1;i--){
        if(a%i==0&&b%i==0){
            c=i;
            break;
        }
    }
    return c;
}

int main(){
    int a,b;
    do{
        cout<<"Nhap a va b (Neu phai nhap lai la do ban da nhap 1 trong hai so a hoac b <=0): "<<endl;
        cin>>a>>b;
    }while(a<=0||b<=0);
    cout<<"bcnn: "<<bcnn(a,b)<<endl<<"ucln: "<<ucln(a,b);
}
