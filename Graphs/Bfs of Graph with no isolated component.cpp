#include<bits/stdc++.h>
using namespace std;

void addEdge(map<int,vector<int>>& adj, int u , int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(map<int,vector<int>>adj)
{
    cout<<"\nPrinting Graph\n";
    for(auto i : adj)
    {
        cout<<i.first<<"->";
        for(auto j : i.second)
        {
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}

vector<int>bfsOfGraph(map<int, vector<int>>adj)
{
    unordered_map<int,int>vis;
    vector<int>bfs;
    for(auto j : adj)
    {
        if(!vis[j.first])
        {
            queue<int>q;
            q.push(j.first);
            vis[j.first]=1;
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
    map<int,vector<int>>adj;
    cout<<"\nAdd edges :\n";
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        addEdge(adj,u,v);
    }
    printGraph(adj);
    vector<int>ans= bfsOfGraph(adj);
    cout<<"\nBFS traversal :\n";
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    return 0;
}

