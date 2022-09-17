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
    
    int minchanges(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>> dp( n+1 , vector<int> (m+1, -1));
        return m+n -2*lcs(word1,word2,n,m,dp);
    }

int main()
{
    string a="sea";
    string b="eat";
    cout<< minchanges(a,b);
    return 0;
}
