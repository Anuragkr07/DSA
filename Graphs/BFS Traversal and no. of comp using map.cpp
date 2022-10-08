/*

    Node Value starts from 1

*/


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

vector<int>bfsOfGraph(int n, map<int, vector<int>>adj)
{
    int count=0;
    unordered_map<int,int>vis;
    vector<int>bfs;
    for(int j=1;j<=n;j++)
    {
        if(!vis[j])
        {
            count++;
            queue<int>q;
            q.push(j);
            vis[j]=1;
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
    cout<<"\nNumber of components :"<<count;
    return bfs;
}

int main()
{
    int n,e;
    cout<<"Enter number of nodes (Node value will start from 1): ";
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
    vector<int>ans= bfsOfGraph(n,adj);
    cout<<"\nBFS traversal :\n";
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    return 0;
}


