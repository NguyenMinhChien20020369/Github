#include <iostream>

using namespace std;

void f(int xval)
{
   int x;
   x = xval;
   cout<<"&x is: "<<&x<<endl;
}
void g(int yval)
{
   int y;
   cout<<"&y is: "<<&y<<endl;
}
int main()
{
   f(7);
   g(11);
   //địa chỉ của hai biến x và y là giống nhau.
   // vì khi f chạy xong biến x sẽ được thu hồi và sau đó chương trình tiếp tục để biến y sử dụng địa chỉ đó.
   return 0;
}
