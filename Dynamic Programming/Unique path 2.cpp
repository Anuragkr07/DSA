// Problem Link : https://leetcode.com/problems/unique-paths-ii/

class Solution {
public:
    int solve(vector<vector<int>>& grid, int m, int n, vector<vector<int>>& dp)
    {
        if(m>=0 && n>=0 && grid[m][n]==1) return 0;
        if(m==0 && n==0) return 1;
        if(m<0 || n<0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        
        return dp[m][n]=solve(grid,m-1,n,dp)+solve(grid,m,n-1,dp);
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(grid,m-1,n-1,dp);
    }
};
