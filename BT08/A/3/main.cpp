#include <iostream>

using namespace std;

void swap_pointers(char*& x, char*& y)
{
   char *tmp;
   tmp = x;
   x = y;
   y = tmp;
}
int main()
{
   char a[] = "I should print second";
   char b[] = "I should print first";

   char *s1 = a;
   char *s2 = b;
   swap_pointers(s1, s2);
   cout << "s1 is " << s1 << endl;
   cout << "s2 is " << s2 << endl;
   return 0;
   // do ta dang tao ra 2 con tro moi x va y de tro den a va b ma thoi nen ta sua x va y thi s1 va s2 khong thay doi
}

