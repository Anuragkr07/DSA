/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.




Constraints:

1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.

*/



#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2 , int n , int m, vector<vector<int>>& dp)
    {
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=0;
        }
        for(int j=0;j<=m;j++)
        {
            dp[0][j]=0;
        }
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]= max(dp[i][j-1] , dp[i-1][j]);
            }
        }       
        return dp[n][m];
    }

int lcs(string s, string t)
{
	int n=s.length();
    int m=t.length();
    vector<vector<int>> dp( n+1 , vector<int> (m+1, -1));
    return lcs(s,t,n,m,dp);
}


int main()
{
    string s="adebc";
    string t="dcadb";
    cout<< lcs(s,t);

    return 0;
}