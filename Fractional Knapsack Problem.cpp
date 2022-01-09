#include <bits/stdc++.h>
using namespace std;
class Fractional_Knapsack
{
public:
    int Object;
    int Value;
    int Weight;
    Fractional_Knapsack(int Object, int Value, int Weight)
    {
        this->Object = Object;
        this->Value = Value;
        this->Weight = Weight;
    }
};

int main()
{
    Fractional_Knapsack* Fractional;
    multimap<int,Fractional_Knapsack*,greater<int>>m;
    map<int,Fractional_Knapsack*>::iterator it;
    int i;
    int Value;
    int Weight;
    int current_Bag_Size=40;
    int total_Profit=0;
    int number_of_Object;
    cout<<"Enter Number of Object: ";
    cin>>number_of_Object;
    cout<<"Enter Value & Weight:"<<endl;
    for(i=1; i<=number_of_Object; i++)
    {
        cin>>Value>>Weight;
        Fractional = new Fractional_Knapsack(i,Value,Weight);
        m.insert(make_pair(Value/Weight,Fractional));
    }
    cout<<endl<<endl<<"Object         "<<"Value          "<<"Weight"<<endl;
    for(it=m.begin(); it != m.end(); it++)
    {
        if(current_Bag_Size >= it->second->Weight)
        {
            total_Profit = total_Profit + it->second->Value;
            current_Bag_Size = current_Bag_Size - it->second->Weight;
            cout<<it->second->Object<<"              "<<it->second->Value<<"              "<<it->second->Weight<<endl;
        }
        else
        {
            total_Profit = total_Profit + (it->first * current_Bag_Size);
            cout<<it->second->Object<<"              "<<it->first * current_Bag_Size<<"              "<<current_Bag_Size<<endl;
            current_Bag_Size = 0;
            break;
        }
    }
    cout<<endl<<endl<<"Total Profit: "<<total_Profit<<endl;
    return 0;
}
/*

7
12 4
12 6
7 3
36 9
60 10
88 11
120 12

*/

