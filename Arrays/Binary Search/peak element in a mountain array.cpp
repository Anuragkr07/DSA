#include<bits/stdc++.h>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
        int s=0,e=arr.size()-1;
        while(s<=e)
        {
            int mid=e+(s-e)/2;
            if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1])
                return mid;
            else if(arr[mid]<arr[mid+1])
                s=mid+1;
            else
                e=mid-1;
        }
        return -1;
    }

int main()
{
    vector<int>arr={0,2,1,0};
    cout<<"Peak element is: "<<arr[peakIndexInMountainArray(arr)];
    
    return 0;
}