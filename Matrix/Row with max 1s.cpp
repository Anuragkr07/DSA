// Problem Link : https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int i = 0;
	    int j = m-1;
	    
	    int ind=-1;
	    while(i<n && j>=0)
	    {
	        if(arr[i][j] == 1)
	        {
	            ind=i;
	            j--;
	        }
	        else
	        {
	            i++;
	        }
	    }
	    return ind;
	}
};


// TC : O(n+m)