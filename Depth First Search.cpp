#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
    int node;
    list<int> *adj;
    bool *is_visited;

    Graph(int node)
    {
        this->node = node;
        adj = new list<int>[node + 1];
        is_visited = new bool[node + 1];
    }

    void addEdge(int source, int destination)
    {
        adj[source].push_back(destination);
        if (source != destination)
            adj[destination].push_back(source);
    }

    void makeList()
    {
        int source, degree, destination;
        for (int i = 1; i <= node; i++)
        {
            cin >> source >> degree;
            for (int i = 1; i <= degree; i++)
            {
                cin >> destination;
                adj[source].push_back(destination);
            }
        }
    }


    void resetVisited()
    {
        for (int i = 1; i <= node; i++)
            is_visited[i] = 0;
    }


    void DFS(int source)
    {
        if (is_visited[source] == 1)
            return;
        is_visited[source] = 1;
        cout << source << " ";
        list<int>::iterator it;
        for (it = adj[source].begin(); it != adj[source].end(); it++)
            if (is_visited[*it] == 0)
                DFS(*it);
    }
};

int main()
{
    cout<<"Enter Node & Edge:"<<endl;
    int node, edge;
    cin >> node >> edge;

    cout<<"Enter Source To Destination:"<<endl;
    Graph graph(node);
    int source, destination;
    for (int i = 1; i <= edge; i++)
    {
        cin >> source >> destination;
        graph.addEdge(source, destination);
    }

    cout<<"Depth First Search:"<<endl;
    graph.resetVisited();
    graph.DFS(1);
}

/*
5 7
1 1
1 2
1 4
1 5
2 3
2 4
3 5
*/
