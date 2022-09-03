#include<bits/stdc++.h>
using namespace std;

int search(vector<int>arr, int n, int low, int high){
        int mid=(low+high)/2;
        if(mid>0 && mid<n-1){
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
                return mid;
            }else if(arr[mid-1]>arr[mid+1]){
                return search(arr, n, low, mid-1);
            }else{
                return search(arr, n, mid+1, high);
            }
        }else if(mid>0){
            if(arr[mid]>arr[mid-1]){
                return mid;
            }else{
                return mid-1;
            }
        }else if(mid<n-1){
            if(arr[mid]>arr[mid+1]){
                return mid;
            }else{
                return mid+1;
            }
        }
        return 0;
    }

int findPeakElement(vector<int>& nums) {
        return search(nums, nums.size(), 0, nums.size()-1);
    }

int main()
{
    vector<int>arr={0,2,1,0};
    cout<<"Peak element is: "<<arr[findPeakElement(arr)];
    
    return 0;
}
