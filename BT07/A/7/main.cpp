#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    string str1= argv[1];
    string str2= argv[2];
    string compstr;
    int temp=0, i=0;
    if(str1.length()>str2.length())
    {
        cout<<0;
    }
    else if(str1.length()==str2.length())
    {
        if(strcmp(str1.c_str(),str2.c_str())==0)
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
    }
    else
    {
        for(; i<str1.length(); ++i)
        {
            compstr+=str2[i];
        }
        do
        {
            if(strcmp(str1.c_str(), compstr.c_str())==0)
            {
                ++temp;
            }
            compstr.erase(0,1);
            if(i==str2.length())
            {
                break;
            }
            compstr+=str2[i];
            ++i;
        }
        while(true);
        cout<<temp;
    }
    return 0;
}
