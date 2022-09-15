#include<bits/stdc++.h>
using namespace std;

int solve(int n , vector<int>& dp)
{
    if(n==1 || n==2)
        return 1;
    if(dp[n-1]!=-1)    return dp[n-1];
    return dp[n-1] = solve(n-1,dp) + solve(n-2,dp);
}

int main()
{
    int n;
    cin>>n;
    vector<int>dp(n,-1);
    int ans=solve(n,dp);
    cout<<ans;
} 
