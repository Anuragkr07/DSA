/*
Find the sum of the contiguous subarray 
within a one-dimensional array of numbers 
that has the largest sum. 

Input: a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
output: Maximum contiguous sum is 7

*/

#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
        int sum=0,maxSum=INT_MIN;
        for(int i:nums)
        {
            sum+=i;
            maxSum=max(maxSum,sum);
            
            if(sum<0)
                sum=0;
        }
        return maxSum;
    }

int main()
{
    vector<int>arr={-1,4,7,2};
    int n=arr.size();
    
    
    int maxSum=maxSubArray(arr);
    
    cout<<maxSum;
    
    return 0;
}

/*

Time Complexity: O(N)
Space Complexity: O(1)

*/
