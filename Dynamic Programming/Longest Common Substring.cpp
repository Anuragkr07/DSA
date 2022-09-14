/*
    Given two strings. The task is to find the length of the longest common substring.

    Example 1:

    Input: S1 = "ABCDGH", S2 = "ACDGHR", n = 6, m = 6
    Output: 4
    Explanation: The longest common substring
    is "CDGH" which has length 4.


    Example 2:

    Input: S1 = "ABC", S2 "ACB", n = 3, m = 3
    Output: 1
    Explanation: The longest common substrings
    are "A", "B", "C" all having length 1.  
*/

#include<bits/stdc++.h>
using namespace std;

int lcsmodified(string s1, string s2 , int n , int m, vector<vector<int>>& dp)
    {
        int ans=0;
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
                {
                    dp[i][j]=1+dp[i-1][j-1];
                    ans=max(dp[i][j],ans);
                }
                    
                else
                    dp[i][j]= 0;              // if no match is found reset the length to 0
            }
        }       
        return ans;
    }
    
    int longestSubstring(string s, string t)
    {
	    int n=s.length();
        int m=t.length();
        vector<vector<int>> dp( n+1 , vector<int> (m+1, -1));
        return lcsmodified(s,t,n,m,dp);
    }


    int main()
    {
        string S1 = "ABCDGH";
        string  S2 = "ACDGHR";
        longestSubstring(S1,S2);  
        
        

        return 0;
    }