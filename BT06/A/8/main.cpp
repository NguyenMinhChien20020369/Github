#include <iostream>

using namespace std;

void combination(int member[],int k,int n)
{
    if(k==-1){
        for(int i=0;i<n;i++)
        {
            if(member[i])cout<<i+1;
        }
        cout<<endl;
    }else
    {
        member[k]=1;
        combination(member,k-1,n);
        member[k]=0;
        combination(member,k-1,n);
    }
}

int main()
{
    int n;
    cin>>n;
    int member[n];
    combination(member,n-1,n);
    return 0;
}
