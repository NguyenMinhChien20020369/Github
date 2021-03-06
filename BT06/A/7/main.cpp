#include <bits/stdc++.h>

using namespace std;

void permutation(string s,int lo,int hi)
{
    if(lo==hi){cout<<s<<endl;return;}
    for(int i=lo;i<=hi;i++)
    {
        swap(s[lo],s[i]);
        permutation(s,lo+1,hi);
        swap(s[lo],s[i]);
    }
}

int main()
{
    string s;
    cin>>s;
    permutation(s,0,s.length()-1);
    return 0;
}
