#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,x,y,cnt=0;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    vector<int>indeg(n,0);
    vector<int>::iterator it;
    for(int i=0; i<m; i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        indeg[y]++;
    }
    queue<int>q;
    for(int i=0; i<n; i++)
        if(indeg[i]==0)
            q.push(i);
    while (!q.empty())
    {
        cnt++;
        int x=q.front();
        q.pop();
        cout<<x<<" ";
        for(auto it:adj[x])
        {
            indeg[it]--;
            if(indeg[it]==0)
                q.push(it);
        }

    }


    cout<<endl<<endl<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<i<<"-->";
        for(it=adj[i].begin(); it!=adj[i].end(); it++)
            cout<<*it<<" ";
        cout<<endl;
    }
    return 0;
}
/*

4 3
0 1
1 2
2 3

*/
