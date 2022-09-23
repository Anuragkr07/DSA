// Problem Link : https://practice.geeksforgeeks.org/problems/filling-bucket0529/1?page=13&category[]=Dynamic%20Programming&sortBy=submissions

class Solution {
  public:
  int solve(int n , vector<int>&dp,int m)
  {
      if(n<0) return 0;
      if(n==0) return 1;
      if(dp[n]!=-1) return dp[n];

      int a=solve(n-1,dp,m);
      int b=solve(n-2,dp,m);
      
      return dp[n]=(a+b)%m;
      
  }
    int fillingBucket(int N) {
        vector<int>dp(N+1,-1);
        int m=pow(10,8);
        return solve(N,dp,m);
    }
};