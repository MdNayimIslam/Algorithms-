#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
    int node;
    list<int> *adj;
    list<int>:: iterator it;

    Graph(int node)
    {
        this->node = node;
        adj = new list<int>[node+1];
    }

    void addEdge(int source, int destination)
    {
        adj[source].push_back(destination);
        if(source != destination)
            adj[destination].push_back(source);
    }

    void printGraph()
    {
        for(int i=1; i<=node; i++)
        {
            cout << i << " -> ";
            for(it=adj[i].begin(); it!=adj[i].end(); it++)
            {
                cout << *it << " ";
            }
            cout << endl;
        }
    }

};

int main()
{
    cout<<"Enter Node & Edge:"<<endl;
    int node, edge;
    cin >> node >> edge;
    Graph object(node);

    int source, destination;
    cout<<"Enter Source To Destination:"<<endl;
    for(int i=1; i<=edge; i++)
    {
        cin >> source >> destination;
        object.addEdge(source,destination);
    }

    cout<<"Adjacency List of above graph is given by:"<<endl;
    object.printGraph();
    return 0;
}
/*
6 6
1 2
1 4
1 5
2 3
2 4
3 5
*/
