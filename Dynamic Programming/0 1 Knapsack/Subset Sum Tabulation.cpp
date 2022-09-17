/*
Given a set of non-negative integers, and a value sum, 
determine if there is a subset of the given set with sum equal to given sum
Example: 
Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output: True  
There is a subset (4, 5) with sum 9.
Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 30
Output: False
There is no subset that add up to 30.
*/

#include <bits/stdc++.h>
using namespace std;
  
bool isSubsetSum(vector<int>arr, int n, int sum, vector<vector<int>>& dp)
{
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(j==0)
                dp[i][j]=1;
            else if(i==0)
                dp[i][j]=0;
                
            else if(arr[i-1]>j)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]= ( dp[i-1][j] || dp[i-1][j-arr[i-1]] );
        }
    }
    return dp[n][sum];
}
  
// Driver code
int main()
{
    vector<int>arr = { 3, 34, 4, 12, 5, 2 };
    int sum = 19;
    int n = arr.size();
    vector<vector<int>> dp( n+1 , vector<int> (sum+1, -1));
    if (isSubsetSum(arr, n, sum,dp) == true)
         cout <<"Found a subset with given sum";
    else
        cout <<"No subset with given sum";
    return 0;
}