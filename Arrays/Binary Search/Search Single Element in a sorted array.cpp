/*

Problem Statement: Given a sorted array of N integers, 
where every element except one appears exactly twice and one element appears only once. 
Search Single Element in a sorted array.


Example 1:

Input: array[] = {1,1,2,3,3,4,4,8,8} 

Output: 2

Explanation: Every element in this sorted array except 2 
appears twice, therefore the answer returned will be 2.
Example 2:

Input: array[] = {11,22,22,34,34,57,57} 

Output: 11

Explanation: Every element in this sorted array except 
11 appears twice, therefore the answer returned will be 11.

*/



#include<bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) 
{
    int l=0,h=nums.size()-2;
    while(l<=h)
    {
        int mid=(l+h)/2;
        if(mid%2==0)
        {
            if(nums[mid]!=nums[mid+1])
                h=mid-1;
            else
                l=mid+1;
        }
        else
        {
            if(nums[mid]==nums[mid+1])
                h=mid-1;
            else
                l=mid+1;
        }
    }
    return nums[l];
}


int main()
{

    vector<int>arr1={1,1,2,3,3,4,4,8,8};
    cout<<singleNonDuplicate(arr1)<<endl;

    vector<int>arr2={11,22,22,34,34,57,57};
    cout<<singleNonDuplicate(arr2)<<endl;

    
    return 0;
}


/*

TC: O(log n)
SC: O(1)

*/
