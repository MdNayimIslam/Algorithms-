#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter the Number of Coins & Amount:"<<endl;
    int Amount,Number_of_Coins;
    cin>>Amount>>Number_of_Coins;

    cout<<"Enter Coins:"<<endl;
    int coins[Number_of_Coins+1];
    for(int i=1; i<=Number_of_Coins; i++)
        cin>>coins[i];


    int table[Number_of_Coins+1][Amount+1];
    memset(table,0,sizeof(table));
    for(int i=0; i<=Amount; i++)
        table[0][i]=INT_MAX;


    for(int r=1; r<=Number_of_Coins; r++)
        for(int c=1; c<=Amount; c++)
        {
            if(coins[r]>c)
                table[r][c]=table[r-1][c];
            else
                table[r][c]=min(table[r-1][c],1+table[r][c-coins[r]]);
        }

    cout<<"Table Amount Coins:"<<endl;
    for(int r=1; r<=Number_of_Coins; r++)
    {
        for(int c=1; c<=Amount; c++)
            cout<<table[r][c]<<" ";
        cout<<endl;
    }

    cout<<"Total Coins:"<<table[Number_of_Coins][Amount];
    return 0;
}

/*
11 4
1
5
6
8
*/

