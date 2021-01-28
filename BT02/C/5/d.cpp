#include <bits/stdc++.h>
using namespace std;
int main(){
    //while(true){
    string s;int do_dai_s;vector<string>ket_qua;

    cin>>s;
    do_dai_s=s.length();
    if(s[0]=='-'){do_dai_s--;}
    reverse(s.begin(),s.end());
    for(int i=0;i<do_dai_s;i++){
        if(i==3){ket_qua.push_back("thousand");}
        if(i==6){ket_qua.push_back("million");}
        switch(s[i]-'0'){
            case 0:
                if(do_dai_s==1){
                    ket_qua.push_back("zero");
                }else
                if((i-0)%3==0&&s[i+1]=='1'){
                    ket_qua.push_back("ten");i++;continue;
                }
            break;
            case 1:
                if((i-0)%3==0&&s[i+1]!='1'){
                    ket_qua.push_back("one");
                }else
                if((i-0)%3==0&&s[i+1]=='1'){
                    ket_qua.push_back("eleven");i++;continue;
                }else
                if((i-2)%3==0){
                    ket_qua.push_back("one hundred");
                }

            break;
            case 2:
                if((i-0)%3==0&&s[i+1]!='1'){
                    ket_qua.push_back("two");
                }else
                if((i-0)%3==0&&s[i+1]=='1'){
                    ket_qua.push_back("twelve");i++;continue;
                }else
                if((i-1)%3==0){
                    ket_qua.push_back("twenty");
                }else
                if((i-2)%3==0){
                    ket_qua.push_back("two hundred");
                }
            break;
            case 3:
                if((i-0)%3==0&&s[i+1]!='1'){
                    ket_qua.push_back("three");
                }else
                if((i-0)%3==0&&s[i+1]=='1'){
                    ket_qua.push_back("thirteen");i++;continue;
                }else
                if((i-1)%3==0){
                    ket_qua.push_back("thirty");
                }else
                if((i-2)%3==0){
                    ket_qua.push_back("three hundred");
                }
            break;
            case 4:
                if((i-0)%3==0&&s[i+1]!='1'){
                    ket_qua.push_back("four");
                }else
                if((i-0)%3==0&&s[i+1]=='1'){
                    ket_qua.push_back("fourteen");i++;continue;
                }else
                if((i-1)%3==0){
                    ket_qua.push_back("fourty");
                }else
                if((i-2)%3==0){
                    ket_qua.push_back("four hundred");
                }
            break;
            case 5:
                if((i-0)%3==0&&s[i+1]!='1'){
                    ket_qua.push_back("five");
                }else
                if((i-0)%3==0&&s[i+1]=='1'){
                    ket_qua.push_back("fifteen");i++;continue;
                }else
                if((i-1)%3==0){
                    ket_qua.push_back("fifty");
                }else
                if((i-2)%3==0){
                    ket_qua.push_back("five hundred");
                }
            break;
            case 6:
                if((i-0)%3==0&&s[i+1]!='1'){
                    ket_qua.push_back("six");
                }else
                if((i-0)%3==0&&s[i+1]=='1'){
                    ket_qua.push_back("sixteen");i++;continue;
                }else
                if((i-1)%3==0){
                    ket_qua.push_back("sixty");
                }else
                if((i-2)%3==0){
                    ket_qua.push_back("six hundred");
                }
            break;
            case 7:
                if((i-0)%3==0&&s[i+1]!='1'){
                    ket_qua.push_back("seven");
                }else
                if((i-0)%3==0&&s[i+1]=='1'){
                    ket_qua.push_back("seventeen");i++;continue;
                }else
                if((i-1)%3==0){
                    ket_qua.push_back("seventy");
                }else
                if((i-2)%3==0){
                    ket_qua.push_back("seven hundred");
                }
            break;
            case 8:
                if((i-0)%3==0&&s[i+1]!='1'){
                    ket_qua.push_back("eight");
                }else
                if((i-0)%3==0&&s[i+1]=='1'){
                    ket_qua.push_back("eighteen");i++;continue;
                }else
                if((i-1)%3==0){
                    ket_qua.push_back("eighty");
                }else
                if((i-2)%3==0){
                    ket_qua.push_back("eight hundred");
                }
            break;
            case 9:
                if((i-0)%3==0&&s[i+1]!='1'){
                    ket_qua.push_back("nine");
                }else
                if((i-0)%3==0&&s[i+1]=='1'){
                    ket_qua.push_back("nineteen");i++;continue;
                }else
                if((i-1)%3==0){
                    ket_qua.push_back("ninety");
                }else
                if((i-2)%3==0){
                    ket_qua.push_back("nine hundred");
                }
            break;

        }
    }
    if(s[s.length()-1]=='-'){ket_qua.push_back("negative");}
    for(int i=ket_qua.size()-1;i>=0;i--){
        cout<<ket_qua[i]<<" ";
    }
    cout<<endl;
    //}
}

