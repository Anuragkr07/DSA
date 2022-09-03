#include<bits/stdc++.h>
using namespace std;
void bubbleSort(vector<int>& arr, int n)
{   
    for(int i=1;i<n;i++)
    {
        bool swapped=false;
        for(int j=0;j<n-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
            
        }
        if(swapped==false)
            break;
    }
}


int main()
{
    vector<int>arr={20,10,80,40,50,60,30};
    int n=arr.size();
    bubbleSort(arr,n);
    for(auto i: arr)
    {
        cout<<i<<" ";
    }
    return 0;
}