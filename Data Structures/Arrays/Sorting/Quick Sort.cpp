#include<bits/stdc++.h>
using namespace std;
int partition( vector<int>&arr, int s, int e) {

    int pivot = arr[s];

    int cnt = 0;
    for(int i = s+1; i<=e; i++) {
        if(arr[i] <=pivot) {
            cnt++;
        }
    }

    //place pivot at the correct position
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    //left and right part
    int i = s, j = e;

    while(i < pivotIndex && j > pivotIndex) {

        while(arr[i] <= pivot) 
        {
            i++;
        }

        while(arr[j] > pivot) {
            j--;
        }

        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }

    }

    return pivotIndex;

}

void quickSort(vector<int>&arr, int s, int e) {

    //base case
    if(s >= e) 
        return ;

    //get partition index
    int p = partition(arr, s, e);

    //left part sorting
    quickSort(arr, s, p-1);

    //right part sorting
    quickSort(arr, p+1, e);

}



int main()
{
    vector<int>arr={20,10,80,40,50,60,30};
    int n=arr.size();
    quickSort(arr,0,n-1);
    for(auto i: arr)
    {
        cout<<i<<" ";
    }
    return 0;
}