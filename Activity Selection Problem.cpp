#include <bits/stdc++.h>
using namespace std;
class activity
{
public:
    int id;
    int start;
    int finish;
    activity(int id, int start, int finish)
    {
        this->id = id;
        this->start = start;
        this->finish = finish;
    }
};

int main()
{
    activity* ac;
    multimap<int,activity*>m;
    map<int,activity*>::iterator it;
    int i;
    int start;
    int finish;
    int current_finish_time=0;
    int total_activity=0;
    int number_of_activity;
    cout<<"Enter Number of Activity: ";
    cin>>number_of_activity;
    cout<<"Enter Start Time & Finish Time:"<<endl;
    for(i=1;i<=number_of_activity;i++)
    {
        cin>>start>>finish;
        ac = new activity(i,start,finish);
        m.insert(make_pair(finish,ac));
    }
    cout<<endl<<endl<<"Activity       "<<"Start Time      "<<"End Time"<<endl;
    for(it=m.begin();it != m.end();it++)
    {
        if(current_finish_time < it->second->start)
        {
            total_activity++;
            current_finish_time=it->first;
            cout<<it->second->id<<"              "<<it->second->start<<"               "<<it->first<<endl;
        }
    }
    cout<<endl<<endl<<"Total Activity: "<<total_activity<<endl;
    return 0;
}
/*

7
1 4
3 6
5 7
2 9
6 10
8 11
9 11

*/
