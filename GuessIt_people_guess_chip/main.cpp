#include<bits/stdc++.h>

using namespace std;

int random_number()
{
    return rand()%100+1;
}

int people_guess(int x)
{
    int n;
    cout<<"Enter your number: ";
    cin>>n;
    if(n<x)
    {
        cout<<"Your number is small"<<endl;
    }
    else if(n>x)
    {
        cout<<"Your number is big"<<endl;
    }
    else cout<<"You win"<<endl;
    return n;
}

void play_GuessIt()
{
    char t;
    do
    {
        int x,a;
        int times=0,point=10000,number=100;
        srand(time(0));
        x=random_number();
        do
        {
            a=people_guess(x);
            times++;
        }
        while(a!=x);
        for(int i=0; i<times-1; i++)
        {
            point-=2*number;
            number--;
        }
        cout<<"Number of guesses is: "<<times<<endl;
        cout<<"The point is: "<<100-times+1<<"/100 and "<<point<<"/10000"<<endl;
        cout<<"Enter "<<'"'<<"y"<<'"'<<" to continue, enter a character that does not match "<<'"'<<"y"<<'"'<<" to stop: ";
        cin>>t;
    }
    while(t=='y');
}

int main()
{
    play_GuessIt();
}
