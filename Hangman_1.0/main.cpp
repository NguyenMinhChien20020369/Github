#include<bits/stdc++.h>
using namespace std;

const int number_of_wrong_guesses_max=7;

const string word_array[]={"angle", "ant", "apple", "arch", "arm", "army","baby", "bag",
        "ball", "band", "basin", "basket", "bath", "bed", "bee", "bell", "berry",
        "bird", "blade", "board", "boat", "bone", "book", "boot", "bottle", "box", "boy",
        "brain", "brake", "branch", "brick", "bridge", "brush", "bucket", "bulb", "button",
        "cake", "camera", "card",  "cart", "carriage", "cat", "chain", "cheese", "chest",
        "chin", "church", "circle", "clock", "cloud", "coat", "collar", "comb", "cord",
        "cow", "cup", "curtain", "cushion",
        "dog", "door", "drain", "drawer", "dress", "drop", "ear", "egg", "engine", "eye",
        "face", "farm", "feather", "finger", "fish", "flag", "floor", "fly",
        "foot", "fork", "fowl", "frame", "garden", "girl", "glove", "goat", "gun",
        "hair", "hammer", "hand", "hat", "head", "heart", "hook", "horn", "horse",
        "hospital", "house", "island", "jewel",  "kettle", "key", "knee", "knife", "knot",
        "leaf", "leg", "library", "line", "lip", "lock",
        "map", "match", "monkey", "moon", "mouth", "muscle",
        "nail", "neck", "needle", "nerve", "net", "nose", "nut",
        "office", "orange", "oven", "parcel", "pen", "pencil", "picture", "pig", "pin",
        "pipe", "plane", "plate", "plow", "pocket", "pot", "potato", "prison", "pump",
        "rail", "rat", "receipt", "ring", "rod", "roof", "root",
        "sail", "school", "scissors", "screw", "seed", "sheep", "shelf", "ship", "shirt",
        "shoe", "skin", "skirt", "snake", "sock", "spade", "sponge", "spoon", "spring",
        "square", "stamp", "star", "station", "stem", "stick", "stocking", "stomach",
        "store", "street", "sun", "table", "tail", "thread", "throat", "thumb", "ticket",
        "toe", "tongue", "tooth", "town", "train", "tray", "tree", "trousers", "umbrella",
        "wall", "watch", "wheel", "whip", "whistle", "window", "wire", "wing", "worm"};
const int word_count=sizeof(word_array)/sizeof(string);
string choose_word(){
    int random_index=rand()%word_count;
    return word_array[random_index];
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
};

void render_game(char& guess_word,string& secret_word,string& guessed_word,int& number_of_wrong_guesses)
{
    cout<<figure[number_of_wrong_guesses]<<endl;
    cout<<guessed_word<<endl<<"Number of wrong guesses: "<<number_of_wrong_guesses<<endl;
    do{
        enter_and_update(guess_word,secret_word,guessed_word,number_of_wrong_guesses);
        cout<<figure[number_of_wrong_guesses]<<endl;
        cout<<guessed_word<<endl<<"Number of wrong guesses: "<<number_of_wrong_guesses<<endl;
    }while(number_of_wrong_guesses<number_of_wrong_guesses_max&&guessed_word!=secret_word);
}

int main(){
    srand(time(0));
    string secret_word=choose_word(),guessed_word;
    initialization(guessed_word,secret_word);
    char guess_word;
    int number_of_wrong_guesses=0,maximum_number_of_wrong_guesses=number_of_wrong_guesses_max;
    render_game(guess_word,secret_word,guessed_word,number_of_wrong_guesses);
    if(number_of_wrong_guesses==number_of_wrong_guesses_max){
        cout<<"You lose. The correct word is "<<secret_word;
    }else cout<<"Congratulations! You win!";
}

