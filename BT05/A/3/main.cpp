#include <iostream>

using namespace std;

void test(int a)
{
    cout<<&a<<endl;
};

void test1(int& a)
{
    cout<<&a<<endl;
};

int main()
{
    int x;
    cout<<&x<<endl;
    test(x);
    test1(x);
    /*
    Địa chỉ của đối số x là 0x61fe1c.
    Địa chỉ của tham trị a là 0x61fdf0.
    Địa chỉ của tham biến a là 0x61fe1c.
    => đpcm
    */
    return 0;
}
