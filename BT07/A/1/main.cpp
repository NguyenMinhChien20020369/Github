#include <iostream>

using namespace std;

int* weird_sum(int a, int b)
{
    int c;
    c=a+b;
    return &c;
}

int main()
{
    //int *pX;
    /*
    int *pX=NULL;
    *pX=0;
    */
    //cout<<*(weird_sum(7,5));
    /*
    int a=20, b=25, *pG;
    {
        int g;
        pG=&g;
        g=a+b;
    }

    {
        int temp=100;
        printf("temp is %d\n", temp);
    }

    printf("GCD(%d,%d)=%d\n", a, b, *pG);
    */
    /*
    {
        int temp1;
        printf("%d\n", &temp1);
    }

    {
        int temp2;
        printf("%d\n", &temp2);
    }
    */
    /*int *ptr1=new int;
    int *ptr2=new int;
    ptr1=ptr2;*/
    /*
    int* p=new int;
    int* p2=p;
    *p=10;
    delete p;
    cout<<*p2;*/

    return 0;
}
