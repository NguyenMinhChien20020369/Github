#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

const int number_of_wrong_guesses_max=7;
const int anti_drift_line_number=30;
const int number_of_figure_lose_begin=8;
const int number_of_figure_lose_end=11;
const int number_of_figure_win_begin=12;
const int number_of_figure_win_end=15;

void to_lower_word(string& s)
{
    transform(s.begin(),s.end(),s.begin(),::tolower);
}
string choose_word()
{
    cout<<"Enter 1 to choose word list 1"<<endl;
    cout<<"Enter 2 to choose word list 2"<<endl;
    cout<<"..."<<endl;
    cout<<"Enter n to choose word list n"<<endl;
    cout<<"There are currently 2 word lists"<<endl;
    char number_of_list;
    cin>>number_of_list;
    string name_of_list;
    name_of_list+="word_array";
    name_of_list+=number_of_list;
    name_of_list+=".txt";
    int word_count=0;
    string word;
    ifstream input(name_of_list);
    while(!input.eof())
    {
        input>>word;
        word_count++;
    }
    ifstream input1(name_of_list);
    int random_number=rand()%word_count+1;
    for(int i=0; i<random_number; i++)
    {
        input1>>word;
    }
    to_lower_word(word);
    return word;
}

void initialization(string& guessed_word,const string& secret_word)
{
    for(int i=0; i<secret_word.length(); i++)
    {
        guessed_word+="-";
    }
}

void enter_and_update(char& guess_word,const string& secret_word,string& guessed_word,int& number_of_wrong_guesses,string& wrong_words)
{
    cout<<"Your guess: ";
    cin>>guess_word;
    bool check=false;
    guess_word=tolower(guess_word);
    for(int i=0; i<secret_word.length(); i++)
    {
        if(secret_word[i]==guess_word)
        {
            check=true;
            guessed_word[i]=guess_word;
        }
    }
    if(!check)
    {
        if(number_of_wrong_guesses==0)
        {
            wrong_words+=guess_word;
        }
        else
        {
            wrong_words+=",";
            wrong_words+=guess_word;
        }
        number_of_wrong_guesses++;
    }
}

const string figure[]=
{
    "   -------------    \n"
    "   |                \n"
    "   |                \n"
    "   |                \n"
    "   |                \n"
    "   |     \n"
    " -----   \n",
    "   -------------    \n"
    "   |           |    \n"
    "   |                \n"
    "   |                \n"
    "   |                \n"
    "   |     \n"
    " -----   \n",
    "   -------------    \n"
    "   |           |    \n"
    "   |           O    \n"
    "   |                \n"
    "   |                \n"
    "   |     \n"
    " -----   \n",
    "   -------------    \n"
    "   |           |    \n"
    "   |           O    \n"
    "   |           |    \n"
    "   |                \n"
    "   |     \n"
    " -----   \n",
    "   -------------    \n"
    "   |           |    \n"
    "   |           O    \n"
    "   |          /|    \n"
    "   |                \n"
    "   |     \n"
    " -----   \n",
    "   -------------    \n"
    "   |           |    \n"
    "   |           O    \n"
    "   |          /|\\  \n"
    "   |                \n"
    "   |     \n"
    " -----   \n",
    "   -------------    \n"
    "   |           |    \n"
    "   |           O    \n"
    "   |          /|\\  \n"
    "   |          /     \n"
    "   |     \n"
    " -----   \n",
    "   -------------    \n"
    "   |           |    \n"
    "   |           O    \n"
    "   |          /|\\  \n"
    "   |          / \\  \n"
    "   |     \n"
    " -----   \n",
    "   -------------    \n"
    "   |           /    \n"
    "   |        _ O     \n"
    "   |       _ /|     \n"
    "   |         \\     \n"
    "   |     \n"
    " -----   \n",
    "   -------------    \n"
    "   |           |    \n"
    "   |           O    \n"
    "   |          /|\\  \n"
    "   |          / \\  \n"
    "   |     \n"
    " -----   \n",
    "   -------------      \n"
    "   |            \\    \n"
    "   |             O _  \n"
    "   |             |\\_ \n"
    "   |              /\\ \n"
    "   |     \n"
    " -----   \n",
    "   -------------    \n"
    "   |           |    \n"
    "   |           O    \n"
    "   |          /|\\  \n"
    "   |          / \\  \n"
    "   |     \n"
    " -----   \n",
    "               O    \n"
    "              /|\\  \n"
    "              / \\  \n",
    "               O /  \n"
    "              /|    \n"
    "              / \\  \n",
    "               O    \n"
    "              /|\\  \n"
    "              / \\  \n",
    "              \\O    \n"
    "               |\\  \n"
    "              / \\  \n",
};

void render_game(char& guess_word,const string& secret_word,string& guessed_word,int& number_of_wrong_guesses,string& wrong_words)
{
    for(int i=0; i<anti_drift_line_number; i++)cout<<endl;
    cout<<figure[number_of_wrong_guesses]<<endl;
    cout<<guessed_word<<endl<<"Number of wrong guesses: "<<number_of_wrong_guesses<<endl;
    cout<<"Wrong words is: "<<wrong_words<<endl;
    do
    {
        enter_and_update(guess_word,secret_word,guessed_word,number_of_wrong_guesses,wrong_words);
        for(int i=0; i<anti_drift_line_number; i++)cout<<endl;
        cout<<figure[number_of_wrong_guesses]<<endl;
        cout<<guessed_word<<endl<<"Number of wrong guesses: "<<number_of_wrong_guesses<<endl;
        cout<<"Wrong words is: "<<wrong_words<<endl;
    }
    while(number_of_wrong_guesses<number_of_wrong_guesses_max&&guessed_word!=secret_word);
}

void play_hang_man()
{
    char myChar;
    do
    {
        srand(time(0));
        string wrong_words;
        const string secret_word=choose_word();
        string guessed_word;
        initialization(guessed_word,secret_word);
        char guess_word;
        int number_of_wrong_guesses=0;
        render_game(guess_word,secret_word,guessed_word,number_of_wrong_guesses,wrong_words);
        if(number_of_wrong_guesses==number_of_wrong_guesses_max)
        {
            for(int k=0; k<2; k++)
            {
                for(int i=number_of_figure_lose_begin; i<=number_of_figure_lose_end; i++)
                {
                    Sleep(500);
                    for(int j=0; j<anti_drift_line_number; j++)cout<<endl;
                    cout<<figure[i]<<endl;
                }
            }
            cout<<"You lose. The correct word is "<<secret_word<<endl;
        }
        else
        {
            for(int k=0; k<2; k++)
            {
                for(int i=number_of_figure_win_begin; i<=number_of_figure_win_end; i++)
                {
                    Sleep(500);
                    for(int j=0; j<anti_drift_line_number; j++)cout<<endl;
                    cout<<figure[i]<<endl;
                }
            }
            cout<<"Number of wrong guesses: "<<number_of_wrong_guesses<<endl;
            cout<<"The correct word is "<<secret_word<<endl;
            cout<<"Congratulations! You win!"<<endl;
        }
        cout<<"Enter "<<'"'<<"y"<<'"'<<" to continue, enter a character that does not match "<<'"'<<"y"<<'"'<<" to stop: ";
        cin>>myChar;
    }
    while(myChar=='y');
}

int main()
{
    play_hang_man();
}

