#include<bits/stdc++.h>
using namespace std;

int random_number(){
    return rand()%100+1;
}

void computer_guess(int& lower_limit,int& upper_limit,char& c){
    cout<<"My guess is number: "<<(lower_limit+upper_limit)/2<<endl<<"Please enter: ";
    cin>>c;
    if(c=='<'){
        lower_limit=(lower_limit+upper_limit)/2+1;
    }else if(c=='>'){
        upper_limit=(lower_limit+upper_limit)/2-1;
    }else cout<<"Computer win"<<endl;
}

void play_GuessIt(){
    char t;
    do{
        int times=0,point=10000,number=100;
        int x,a,lower_limit=1,upper_limit=100;char c;
        cout<<"Enter your number: ";
        cin>>x;
        do{
            computer_guess(lower_limit,upper_limit,c);
            times++;
        }while(c!='=');
    for(int i=0;i<times-1;i++){
        point-=2*number;number--;
    }
    cout<<"Number of guesses is: "<<times<<endl;
    cout<<"The point is: "<<100-times+1<<"/100 and "<<point<<"/10000"<<endl;
    cout<<"Enter "<<'"'<<"y"<<'"'<<" to continue, enter a character that does not match "<<'"'<<"y"<<'"'<<" to stop: ";
    cin>>t;
}while(t=='y');
}

int main(){
    play_GuessIt();
}

