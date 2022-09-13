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

int lcs(string s, string t, vector<vector<int>>& dp)
{
	int n=s.length();
    int m=t.length();
    
    return lcs(s,t,n,m,dp);
}


int main()
{
    string s="adebc";
    string t="dcadb";
    int n=s.length();
    int m=t.length();
    vector<vector<int>> dp( n+1 , vector<int> (m+1, -1));
    cout<< lcs(s,t,dp)<<endl;
    for(int i=0;i<n+1;i++)
    {
       for(int j=0;j<m+1;j++)
       {
           cout<<dp[i][j]<<" ";
       }
       cout<<endl;
    }
    
    string ans="";
    
    int i=n,j=m;
    while(i>0 && j>0)
    {
        if(s[i-1]==t[j-1]){
            ans.push_back(s[i-1]);
            i--;
            j--;
        }
        else
        {
            if( dp[i][j-1] > dp[i-1][j] )
            {
                j--;
            }
            else
            {
                i--;
            }
        }
        
    }
    cout<<"\n";
    
    // Print in reverse
    
    for(int i=ans.length() ; i>=0 ; i--)
        cout<<ans[i];

    return 0;
}