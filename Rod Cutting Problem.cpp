#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter Rod Size:";
    int rod_size;
    cin>>rod_size;

    cout<<"Enter The price of each size of rod:"<<endl;
    int value[rod_size+1];
    for(int i=1; i<=rod_size; i++)
        cin>>value[i];

    int table[rod_size+1][rod_size+1];
    memset(table,0,sizeof(table));

    cout<<"\tTable"<<endl;
    cout<<"---------------------"<<endl;
    for(int r=1; r<=rod_size; r++)
    {
        for(int c=1; c<=rod_size; c++)
        {
            if(r>c)
                table[r][c] = table[r-1][c];
            else
                table[r][c] = max(table[r-1][c], value[r] + table[r][c-r]);
            cout<<table[r][c]<<" ";
        }
        cout<<endl;
    }
    cout<<"Maximum value: "<<table[rod_size][rod_size]<<endl;
    return 0;
}

/*

8
1
5
8
9
10
17
17
20

*/
