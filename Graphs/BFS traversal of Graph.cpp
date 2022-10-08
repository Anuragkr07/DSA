#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>>& adj, int u , int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// only the nodes connected to 0 node

vector<int>bfsOfGraph(int n, vector<vector<int>>adj)
{
    vector<int>vis(n,0);
    vis[0]=1;
    queue<int>q;
    q.push(0);
    vector<int>bfs;
    
    while(!q.empty())
    {
        auto node= q.front();
        q.pop();
        bfs.push_back(node);
        
        for(auto it: adj[node])
        {
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
    return bfs;
}

int main()
{
    int n,e;
    cout<<"Enter number of nodes : ";
    cin>>n;
    cout<<"\nEnter number of edges : ";
    cin>>e;
    vector<vector<int>>adj(n+1);
    cout<<"\n Add edges :\n";
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        addEdge(adj,u,v);
    }
    vector<int>bfs = bfsOfGraph(n,adj);
    for(auto i: bfs)
    {
        cout<<i<<" ";
    }
    return 0;
}
