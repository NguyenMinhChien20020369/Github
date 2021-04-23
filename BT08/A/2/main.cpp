#include <iostream>

using namespace std;

int main( )
{
   /*char a[4] = "abc";
   for (char *cp = a; (*cp) != '\0'; cp++) {
      cout << (void*) cp << " : " << (*cp) << endl;
   }
   return 0;*/

   /*int a[3] = {3,6,4};
   int times=0;
   for (int *cp = a; times<3; cp++) {
      cout << cp << " : " << (*cp) << endl;
        times++;
   }
   return 0;*/

   double a[3] = {3,6,4};
   int times=0;
   for (double *cp = a; times<3; cp++) {
      cout << cp << " : " << (*cp) << endl;
        times++;
   }

   //thay cp++ bang cp+=2 thi gia tri cua hai con tro chenh lech 10
   return 0;
}
