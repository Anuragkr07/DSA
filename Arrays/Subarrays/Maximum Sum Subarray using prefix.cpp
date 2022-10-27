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
    
    vector<int>prefix(n+1);
    prefix[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        prefix[i]=prefix[i-1]+arr[i];
    }
    
    int maxSum=INT_MIN;
    
    for(int i=1;i<=n;i++)
    {
        int sum=0;
        maxSum=max(maxSum,prefix[i]);
        for(int j=1;j<i;j++)
        {
            sum=prefix[i]-prefix[j-1];
            maxSum=max(maxSum,sum);
        }
    }
    
    cout<<maxSum;
    
    return 0;
}


/*

Time Complexity: O(N^2)
Space Complexity: O(N)

 */