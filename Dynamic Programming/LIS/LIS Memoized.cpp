#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int i , int prev, vector<int>& nums, int n, vector<vector<int>>& dp)
    {
        if(i<0) return 0;
        if(dp[i][prev-1]!=-1) return dp[i][prev-1];
        int take=0;
        
        if(prev==n || nums[i] < nums[prev])
            take= 1 + solve(i-1,i,nums,n,dp);                
        
           int dont=solve(i-1,prev,nums,n,dp);
                    
        return dp[i][prev-1] = max(take,dont);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(n-1,n,nums,n,dp);
    }
};