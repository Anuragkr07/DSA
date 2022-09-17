#include <bits/stdc++.h>
using namespace std;

int knapSack(vector<int>& wt, vector<int>& val ,int W, int n, vector<vector<int>>& dp)
{
    for(int i=1; i<n+1;i++)
    {
        for(int j=1;j<W+1;j++)
        {
          if(wt[i-1] > W)
          {
            dp[i][j]= dp[i-1][j];
          }
    
          else
          {
            dp[i][j]= max( val[i-1] + dp[i-1][j-wt[i-1]] , dp[i-1][j] );
          }  
        }
    }
    return dp[n][W];
}
 

int main()
{
    vector<int>val = { 60, 100, 120 };
    vector<int>wt = { 10, 20, 30 };
    int W = 50;
    int n=val.size();
    vector<vector<int>> dp( n+1 , vector<int> (W+1,-1));
    for(int i=0;i<W+1;i++)
    {
        dp[0][i]=0;
    }
    for(int j=0;j<n+1;j++)
    {
        dp[j][0]=0;
    }
    
    cout << knapSack(wt, val, W, n, dp);
    return 0;
}