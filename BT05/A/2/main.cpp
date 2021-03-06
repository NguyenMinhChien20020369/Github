#include <iostream>

using namespace std;

int factorial(int x)
{
    if(x==0){
        cout<<"x ="<<x<<" at "<<&x<<endl;
        return 1;
    }else
    {
        cout<<"x ="<<x<<" at "<<&x<<endl;
        return x*factorial(x-1);
    }
}

int main()
{
    factorial(5);
    // Các biến x cách nhau 48 byte
    // Kích thước của một stack frame cho hàm factorial là 48 byte
    return 0;
}
