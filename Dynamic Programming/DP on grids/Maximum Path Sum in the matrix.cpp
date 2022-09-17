// Problem Link : https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

int solve(int i , int j , vector<vector<int>>& mat, vector<vector<int>>& dp)
{
    if(j<0 || j>=mat[0].size() ) return -1e9;
    if(i==0) return mat[0][j];
    if(dp[i][j]!=-1)return dp[i][j];
    int up=mat[i][j] + solve(i-1,j,mat,dp);
    int ul=mat[i][j] + solve(i-1,j-1,mat,dp);
    int ur=mat[i][j] + solve(i-1,j+1,mat,dp);
    
    return dp[i][j]=max(up,max(ul,ur));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int m=matrix.size();
    int n=matrix[0].size();
    int maxi=-1e9;
    vector<vector<int>> dp( m , vector<int> (n, -1));
    for(int j=0;j<n;j++)
    {
        maxi=max(maxi,solve(m-1,j,matrix,dp));
    }
    return maxi;
}