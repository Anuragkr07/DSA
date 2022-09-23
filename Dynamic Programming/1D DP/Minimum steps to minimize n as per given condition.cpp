// Problem Link : https://practice.geeksforgeeks.org/problems/minimum-steps-to-minimize-n-as-per-given-condition0618/1?page=8&category[]=Dynamic%20Programming&sortBy=submissions

class Solution{

	public:
	int solve(int n , vector<int>&dp)
	{
	    if(n==1)
	    return 0;
	    if(dp[n]!=-1) return dp[n];
	  	
	  	int a,b,c;
	    a=b=c=INT_MAX;
	    if(n%2==0)
	        a=solve(n/2,dp)+1;
	    if(n%3==0)
	        b = solve(n/3,dp)+1;

	    c = solve(n-1,dp)+1;
	    
	    int ans =min(min(a,b),c); 
	    
	    return dp[n]=ans;
	}
	
	int minSteps(int N) 
	{ 
	    // Your code goes here
	    vector<int>dp(N+1,-1);
	    return solve(N,dp);
	} 
};