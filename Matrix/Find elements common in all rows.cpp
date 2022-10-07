// Problem Link : https://www.geeksforgeeks.org/common-elements-in-all-rows-of-a-given-matrix/


#include <bits/stdc++.h>
using namespace std;

#define M 4
#define N 5

vector<int> printCommonElements(int mat[M][N], vector<int>& ans)
{

	unordered_map<int,int>m;
	for(int i=0;i<N;i++)
	{
	    m[mat[0][i]]=1;
	}
	
	for(int i=1;i<M;i++)
	{
	    for(int j=0;j<N;j++)
	    {
	        if(m[mat[i][j]] == i)
	        {
	            m[mat[i][j]]++;
	        }
	        
	        if( i== M-1 && m[mat[i][j]] == M)
	            ans.push_back(mat[i][j]);
	    }
	}
	
	return ans;
}

// driver program to test above function
int main()
{
	int mat[M][N] =
	{
		{1, 2, 2, 4, 8},
		{3, 2, 8, 5, 1},
		{8, 7, 2, 3, 1},
		{8, 1, 2, 7, 9},
	};

	vector<int>ans;
	printCommonElements(mat,ans);
	cout<<"Printing elements : ";
	for(auto i: ans)
	{
	    cout<<i<<" ";
	}

	return 0;
}


// TC : O(m*n)