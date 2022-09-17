/*

https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

*/


#define mod 1000000007;

int func(int n, vector<int>& dp)
{
    if(n<=0)
    {
        return (n==0);
    }
    
    if(dp[n]!=-1)
        return dp[n];
    
    dp[n]=(func(n-1,dp) + func(n-2,dp))%mod;
    return dp[n];
}

int countDistinctWays(int n) {
    //  Write your code here.
    vector<int>dp(n+1,-1);
    return func(n,dp);
}