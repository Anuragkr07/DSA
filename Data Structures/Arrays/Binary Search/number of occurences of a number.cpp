#include<bits/stdc++.h>
using namespace std;

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int,int>ans;
    int s=0,e=n-1;
    int a=-1;
    while(s<=e)
    {
        int mid=e+((s-e)/2);
        if(arr[mid]>k)
            e=mid-1;
        else if(arr[mid]<k)
            s=mid+1;
        else
        {
            e=mid-1;
            a=mid;
        }
        ans.first=a;
    }
    
    s=0,e=n-1;
    int b=-1;
    while(s<=e)
    {
        int mid=e+((s-e)/2);
        if(arr[mid]>k)
            e=mid-1;
        else if(arr[mid]<k)
            s=mid+1;
        else
        {
            s=mid+1;
            b=mid;
        }
        ans.second=b;
    }
    return ans;
}

int main()
{
    vector<int>arr={0, 0, 1, 1, 2, 2, 2, 2};
    int k=2;
    pair<int,int>ans=firstAndLastPosition(arr,arr.size(),k);
    cout<<"Number of occurence of k is: "<<ans.second-ans.first+1;
    return 0;
}