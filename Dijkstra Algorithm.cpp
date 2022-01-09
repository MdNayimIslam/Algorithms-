#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int node;
    list<pair<int,int>> *graph;
    int *cost;
    int *parent;

    Graph(int node)
    {
        this->node = node;
        graph = new list<pair<int,int>>[node + 1];
        cost = new int[node + 1];
        parent = new int[node + 1];
    }

    void addEdge(int source, int destination, int weight)
    {
        graph[source].push_back({ destination, weight});
        // undirected
        // if (source != destination)
        // graph[destination].push_back({ source, weight});
    }

    void reset()
    {
        for (int i = 1; i <= node; i++)
        {
            cost[i]=INT_MAX;
            parent[i]=-1;
        }
    }

    void Dijkstra(int src)
    {
        reset();
        priority_queue<pair<int,int>> Q;
        list<pair<int,int>> :: iterator it;

        cost[src]=0;
        parent[src]=src;
        Q.push(make_pair(cost[src],src));


        while(!Q.empty())
        {
            int x = Q.top().second;
            Q.pop();
            for(it = graph[x].begin(); it != graph[x].end(); it++)
                if(cost[x] + it->second < cost[it->first])
                {
                    cost[it->first] = cost[x] + it->second;
                    parent[it->first] = x ;
                    Q.push(make_pair(cost[it->first], it->first));
                }
        }
        cout<<"Node \tcost \tparent"<<endl;
        for(int i=1; i<=node; i++)
            cout<<i<<"  \t"<<cost[i]<<"  \t"<<parent[i]<<endl;
    }
};

int main()
{
    cout<<"Enter Node & Edge:"<<endl;
    int node, edge, source, destination, weight, src;
    cin>>node>>edge;

    cout<<"Enter Source To Destination with weight:"<<endl;
    Graph graph(node);
    for (int i = 1; i <= edge; i++)
    {
        cin >> source >> destination >> weight;
        graph.addEdge(source, destination, weight);
    }

    cout<<"Enter Source:"<<endl;
    cin>>src;
    cout<<"   Path Relaxation"<<endl;
    cout<<"----------------------"<<endl;
    graph.reset();
    graph.Dijkstra(src);
}

/*

5 10
1 2 10
1 3 5
3 2 3
2 3 2
2 4 1
3 4 9
3 5 2
5 4 6
4 5 4
5 1 7
1

*/
