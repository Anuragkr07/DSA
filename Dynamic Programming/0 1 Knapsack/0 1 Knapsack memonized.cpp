#include <bits/stdc++.h>
using namespace std;

int knapSack(vector<int>& wt, vector<int>& val ,int W, int n, vector<vector<int>>& dp)
{
 
    /* 
        Base Case
        if there is no item in the array or 
        if the capacity of the bag is 0
    */
    if (n==0 || W==0)     
        return 0;
        
    if(dp[n][W]!=-1)
        return dp[n][W];
 
 /*
    if the item's weight is greater than
    the capacity of the knapsack
 */
    if (wt[n - 1] > W)
        return knapSack(wt, val, W, n-1, dp);
 
    
    else
        return dp[n][W] =  max(
            val[n - 1] + knapSack(wt , val , W-wt[n-1] , n-1, dp) ,
                knapSack(wt, val, W,  n-1, dp)
            );
}
 

int main()
{
    vector<int>val = { 60, 100, 120 };
    vector<int>wt = { 10, 20, 30 };
    int W = 50;
    int n=val.size();
    vector<vector<int>> dp( n+1 , vector<int> (W+1, -1));
    cout << knapSack(wt, val, W, n, dp);
    return 0;
}