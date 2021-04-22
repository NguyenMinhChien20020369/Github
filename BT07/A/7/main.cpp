#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char** argv)
{
    string str1= argv[1];
    string str2= argv[2];
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

    }
    //strcmp();
    return 0;
}
