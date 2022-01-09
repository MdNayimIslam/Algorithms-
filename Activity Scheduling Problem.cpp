#include <bits/stdc++.h>
using namespace std;
class Activity_Scheduling
{
public:
    int Object;
    int Value;
    int Waiting_Time;
    Activity_Scheduling(int Object, int Value, int Waiting_Time)
    {
        this->Object = Object;
        this->Value = Value;
        this->Waiting_Time = Waiting_Time;
    }
};

int main()
{
    Activity_Scheduling* Scheduling;
    multimap<int,Activity_Scheduling*,greater<int>>m;
    map<int,Activity_Scheduling*>::iterator it;
    int i;
    int Value;
    int Waiting_Time;
    int total_Profit=0;
    int number_of_Object;

    cout<<"Enter Number of Object: ";
    cin>>number_of_Object;
    cout<<"Enter Value & Waiting_Time:"<<endl;
    for(i=1; i<=number_of_Object; i++)
    {
        cin>>Value>>Waiting_Time;
        Scheduling = new Activity_Scheduling(i,Value,Waiting_Time);
        m.insert(make_pair(Value,Scheduling));
    }

    int deadlin[number_of_Object+1]= {0};
    int Profit[number_of_Object+1]= {0};
    int ID[number_of_Object+1]= {0};


    for(it=m.begin(); it != m.end(); it++)
    {
        for(i=it->second->Waiting_Time; i>0; i--)
        {
            if(deadlin[i]==0)
            {
                ID[i] = it->second->Object;
                Profit[i] = it->second->Value;
                deadlin[i] = it->second->Waiting_Time;
                break;
            }
        }
    }

    cout<<endl<<endl<<"Object         "<<"Value          "<<"Waiting_Time"<<endl;
    for(i=1; i<number_of_Object; i++)
    {
        if(deadlin[i]!=0)
        {
            cout<<ID[i]<<"              "<<Profit[i]<<"              "<<deadlin[i]<<endl;
            total_Profit = total_Profit + Profit[i];
        }
    }
    cout<<endl<<endl<<"Total Profit: "<<total_Profit<<endl;
    return 0;
}
/*

7
12 1
5 2
20 2
15 3
35 3
25 4
30 4

*/

