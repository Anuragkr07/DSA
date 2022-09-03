/*
    Given a sorted array in which all elements appear twice (one after one) 
    and one element appears only once. 
    Find that element in O(log n) complexity.
*/

#include<bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) 
{
        int n = nums.size();
        // Checking the boundary first
        if(n == 1)
        {
            return nums[0];   // if there is only single element in the array
        }
        
        if(nums[0] != nums[1]){
            return nums[0];         // if the first and the second element are not equal
        }
        
        if(nums[n-1] != nums[n-2]){
            return nums[n-1];        //if the last and the second last element are not equal
        }
        
        int s = 0, e=n-1;
        
        while(s <= e){
            int mid = s + (e - s) / 2;
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
                return nums[mid];
            }
            // check if it is left half or right half
            else if((nums[mid] == nums[mid+1] && mid%2==0) || (mid%2!=0 && nums[mid]== nums[mid-1]))
            {
                s = mid + 1;          // on left side
            }
            else
            {
                e = mid - 1;           // right side
            }                        
        }
        return -1;
}

int main()
{
    vector<int>arr={1,1,2,3,3,4,4,8,8};
    cout<<singleNonDuplicate(arr);

    return 0;
}