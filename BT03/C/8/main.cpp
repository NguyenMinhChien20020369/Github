#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long number_of_patients,number_of_patients_max;double total_waiting_time=0;
    number_of_patients_max=15990000;
    cin>>number_of_patients;
    vector<int> examination_time(number_of_patients);
    for(int i=0;i<number_of_patients;i++)
    {
        cin>>examination_time[i];
        //examination_time[i]=(abs(rand())%INT_MAX)+1;
    }
    sort(examination_time.begin(),examination_time.end());
    for(int i=0;i<number_of_patients;i++)
    {
        total_waiting_time+=(number_of_patients-1-i)*examination_time[i];
    }
    cout<<total_waiting_time;
    return 0;
}
