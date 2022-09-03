/*
Find the sum of the contiguous subarray 
within a one-dimensional array of numbers 
that has the largest sum. 

Input: a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
output: Maximum contiguous sum is 7

*/


#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>arr={-1,4,7,2};
    int n=arr.size();
    
    int maxSum=INT_MIN;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int sum=0;
            for(int k=i;k<=j;k++)
            {
                sum+=arr[k];
            }
            maxSum=max(maxSum,sum);
        }
    }
    
    cout<<maxSum;
    
    
    return 0;
}



/*

TC: O(n^3)
SC: O(1)

*/