#include <iostream>

using namespace std;

void reverse(char a[], int aSize)
{
    char tmp;
    for(int i=0;i<aSize/2;i++)
    {
        tmp=*(a+i);
        *(a+i)=*(a+aSize-i-1);
        *(a+aSize-i-1)=tmp;
    }
}

void delete_char(char a[], char c, int aSize)
{
    for(int i=0;i<aSize;i++)
    {
        if(*(a+i)==c)
        {
            aSize--;
            for(int j=i;j<aSize;j++)
            {
                *(a+j)=*(a+j+1);
            }
            i--;
            *(a+aSize)='\0';
        }
    }
}

void pad_right(char*& a, int n, int aSize)
{
    if(aSize+1>=n){return;}
    char* newArr= new char[n];
    for(int i=0;i<aSize;i++)
    {
        *(newArr+i)=*(a+i);
    }
    for(int i=aSize;i<n-1;i++)
    {
        *(newArr+i)=' ';
    }
    *(newArr+n-1)='\0';
    a=newArr;
}

void pad_left(char*& a, int n, int aSize)
{
    if(aSize+1>=n){return;}
    char* newArr= new char[n];
    for(int i=0;i<n-aSize-1;i++)
    {
        *(newArr+i)=' ';
    }
    for(int i=n-aSize-1;i<n-1;i++)
    {
        *(newArr+i)=*(a+i-(n-aSize-1));
    }
    *(newArr+n-1)='\0';
    a=newArr;
}

void truncate(char a[], int n, int aSize)
{
    if(aSize+1<=n)
    {
        return;
    }
    *(a+n-1)='\0';
}

bool is_palindrome(char a[], int aSize)
{
    for(int i=0;i<aSize/2;i++)
    {
        if(*(a+i)!=*(a+aSize-i-1)){return false;}
    }
    return true;
}

void trim_left(char a[], int aSize)
{
    while(*a==' ')
    {
        aSize--;
        for(int i=0;i<aSize;i++)
        {
            *(a+i)=*(a+i+1);
        }
        *(a+aSize)='\0';
    }
}

void trim_right(char a[], int aSize)
{
    while(*(a+aSize-1)==' ')
    {
        aSize--;
        *(a+aSize)='\0';
    }
}

int main()
{
    /*char a[]="abba    ";
    trim_right(a, 8);
    cout<<a<<".";*/

    /*char a[]="    abba";
    trim_left(a, 8);
    cout<<a;*/

    /*char a[5]="abba";
    cout<<is_palindrome(a, 4);*/

    /*char a[4]="abc";
    truncate(a, 2, 3);
    cout<<a;*/

    /*char* a="abc";
    pad_left(a, 6, 3);
    cout<<a;*/

    /*char* a="abc";
    pad_right(a, 6, 3);
    cout<<a<<".";*/

    /*char a[10]="abcbdbsab";
    char c='a';
    delete_char(a, c, 9);
    cout<<a;*/

    /*char a[4]="abc";
    reverse(a, 3);
    cout<<a;*/
    return 0;
}
