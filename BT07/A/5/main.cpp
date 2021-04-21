#include <iostream>

using namespace std;

char* weird_string() {
   char c[] = "123345";
   return c;
}

int main()
{
    cerr<<weird_string();
    return 0;
    //khong canh bao, khong co output
}
