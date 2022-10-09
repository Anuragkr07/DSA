// Problem Link : https://leetcode.com/problems/number-of-provinces/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bfsOfGraph(int n, map<int, vector<int>>adj)
{
    int count=0;
    unordered_map<int,int>vis;
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
    return count;
}

    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
        map<int,vector<int>>adj;
		
// ------------------------------------------------------------------------------------------------- 

		// converting adjacency matrix to adjacency list ( 1- based )
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                if(isConnected[i][j]==1 and i!=j)
                {
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        
// -------------------------------------------------------------------------------------------------

        int cnt=bfsOfGraph(v,adj);
        return cnt;

    }
};