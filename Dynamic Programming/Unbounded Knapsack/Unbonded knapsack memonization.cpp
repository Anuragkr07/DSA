// Problem Link : https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029?leftPanelTab=0


#include <bits/stdc++.h> 
int solve(vector<int> &wt , vector<int> &profit ,int W , int n , vector<vector<int>>& dp)
{
    if(n==0 || W==0)
        return 0;
    if(dp[n][W]!=-1)
        return dp[n][W];
    if(W<wt[n-1])
        return solve(wt,profit,W,n-1,dp);
    else
        return dp[n][W] = max( solve(wt,profit,W,n-1,dp) , profit[n-1] + solve(wt,profit,W-wt[n-1],n,dp));
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
    return solve(weight,profit,w,n,dp);
}