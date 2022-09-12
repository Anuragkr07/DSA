/*
Given a set of non-negative integers, and a value sum, 
determine if there is a subset of the given set with sum equal to given sum


Example: 

Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output: True  
There is a subset (4, 5) with sum 9.

Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 30
Output: False
There is no subset that add up to 30.

*/


#include <bits/stdc++.h>
using namespace std;
  
bool isSubsetSum(vector<int>arr, int n, int sum)
{
    if(sum==0)
        return true;
    if(n==0)
        return false;
        
    if(arr[n-1]>sum)
        return isSubsetSum(arr , n-1 , sum);
    else
        return ( isSubsetSum(arr, n-1, sum) || isSubsetSum(arr , n-1 , sum-arr[n-1]) );
}
  
// Driver code
int main()
{
    vector<int>arr = { 3, 34, 4, 12, 5, 2 };
    int sum = 100;
    int n = arr.size();
    if (isSubsetSum(arr, n, sum) == true)
         cout <<"Found a subset with given sum";
    else
        cout <<"No subset with given sum";
    return 0;
}