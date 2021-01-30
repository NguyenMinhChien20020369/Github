#include<bits/stdc++.h>
using namespace std;

string choose_word(){
    return "book";
}

void initialization(string& guessed_word,string& secret_word){
    for(int i=0;i<secret_word.length();i++){
        guessed_word+="-";
    }
}

void enter_and_update(char& guess_word,string& secret_word,string& guessed_word,int& number_of_wrong_guesses){
    cout<<"Your guess: ";
    cin>>guess_word;bool check=false;
    for(int i=0;i<secret_word.length();i++){
        if(secret_word[i]==guess_word){
            check=true;
            guessed_word[i]=guess_word;
        }
    }
    if(!check){
            number_of_wrong_guesses++;
        }
}

int main(){
    string secret_word=choose_word(),guessed_word;
    initialization(guessed_word,secret_word);
    char guess_word;
    int number_of_wrong_guesses=0,maximum_number_of_wrong_guesses=7;
    cout<<guessed_word<<endl<<"Number of wrong guesses: "<<number_of_wrong_guesses<<endl;
    do{
        enter_and_update(guess_word,secret_word,guessed_word,number_of_wrong_guesses);
        cout<<guessed_word<<endl<<"Number of wrong guesses: "<<number_of_wrong_guesses<<endl;
    }while(number_of_wrong_guesses<7&&guessed_word!=secret_word);
    if(number_of_wrong_guesses==7){
        cout<<"You lose. The correct word is "<<secret_word;
    }else cout<<"Congratulations! You win!";
}
