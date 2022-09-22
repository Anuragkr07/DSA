// Problem Link : https://leetcode.com/problems/longest-increasing-subsequence/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i , int prev, vector<int>& nums, int n)
    {
        if(i<0) return 0;
        
        int take=0;
        
        if(prev==n || nums[i] < nums[prev])
            take= 1 + solve(i-1,i,nums,n);                
        
           int dont=solve(i-1,prev,nums,n);
                    
        return  max(take,dont);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(n-1,n,nums,n);
    }
};