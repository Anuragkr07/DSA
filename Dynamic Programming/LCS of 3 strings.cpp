#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    int dp[n1+1][n2+1][n3+1];
        for(int i=0;i<n1+1;i++)
        {
            for(int j=0;j<n2+1;j++)
            {
                for(int k=0;k<n3+1;k++)
                {
                    if(i==0||j==0||k==0)
                    dp[i][j][k]=0; 
                }
                
            }
        }
        
        for(int i=1;i<n1+1;i++)
        {
            for(int j=1;j<n2+1;j++)
            {
                for(int k=1;k<n3+1;k++)
                {
                if(A[i-1]==B[j-1] && A[i-1]==C[k-1])
                dp[i][j][k]= 1+dp[i-1][j-1][k-1]; 
                    
                else
                dp[i][j][k]= max(max(dp[i-1][j][k], dp[i][j-1][k]), dp[i][j][k-1]); 
                }
            }
        }
        return dp[n1][n2][n3];
}


int main()
{
   string A = "geeks";
   string  B = "geeksfor";
   string C = "geeksforgeeks";

   cout<<LCSof3(A,B,C,A.length(),B.length(),C.length());
   
   return 0;
}