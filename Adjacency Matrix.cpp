#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter Node & Edge:"<<endl;
    int node, edge, source, destination;
    cin >> node >> edge;
    int Graph[node][edge];
    memset(Graph,0,sizeof(Graph));

    cout<<"Enter Source To Destination:"<<endl;
    for(int i=0; i<edge; i++)
    {
        cin>>source>>destination;
        Graph[source][destination]=1;
        Graph[destination][source]=1;
    }

    cout<<"Adjacency Matrix of above graph is given by:"<<endl;
    for(int r=0; r<node; r++)
    {
        for(int c=0; c<edge; c++)
            cout<<Graph[r][c]<<"  ";
        cout<<endl;
    }
    return 0;
}


/*

7 7
1 2
1 3
2 4
2 5
2 6
2 7
7 3

    */


