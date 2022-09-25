// Problem Link : https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1


#include<bits/stdc++.h>
using namespace std;

class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        long long res=0;
        for(int i=0;i<K;i++)
            res+=Arr[i];
        long long currSum=res;
        for(int i=K;i<N;i++)
        {
            currSum+=Arr[i];      // add the next element
            currSum-=Arr[i-K];    // remove the previous element
            res=max(res,currSum);
        }
        
        return res;
    }
};