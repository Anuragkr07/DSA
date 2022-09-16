// Problem Link : https://www.codingninjas.com/codestudio/problems/triangle_1229398?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0


#include <bits/stdc++.h> 
int solve(int i, int j, vector<vector<int>>& mat, int n , vector<vector<int>>& dp)
{
    if(i==n) return mat[i][j];
    if(dp[i][j]!= -1) return dp[i][j];
    int down=mat[i][j]+solve(i+1,j,mat,n,dp);
    int right=mat[i][j]+solve(i+1,j+1,mat,n,dp);
    return dp[i][j] = min( down , right );
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<vector<int>>dp(n,vector<int>(n,-1));
  return solve(0,0,triangle,n-1,dp);
    
}
