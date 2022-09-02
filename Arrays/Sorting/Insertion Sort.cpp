#include<bits/stdc++.h>
using namespace std;
void insertionSort(vector<int> &arr)
{
    int n=arr.size();
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        int temp=arr[i];
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}


int main()
{
    vector<int>arr={20,10,80,40,50,60,30};
    insertionSort(arr);
    for(auto i: arr)
    {
        cout<<i<<" ";
    }
    return 0;
}