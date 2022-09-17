// Problem Link : https://leetcode.com/problems/house-robber-ii/


class Solution {
public:
    int solve(vector<int>nums , int n, vector<int>& dp)
    {
        if(n==0)
            return nums[0];
        if(n<0)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        
        return dp[n]=max(nums[n]+solve(nums,n-2,dp),solve(nums,n-1,dp) );
    }
    
    int rob1(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(nums,n-1,dp);
    }
    
    int rob(vector<int>& nums) {
        vector<int>a,b;
        int n=nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        for(int i=0;i<n;i++)
        {
            if(i!=0) a.push_back(nums[i]);
            if(i!=n-1) b.push_back(nums[i]);
        }
        return max(rob1(a) , rob1(b));
        
    }
};
