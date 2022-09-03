/*
  Merge Sort
  Pre-requisite : Merge 2 sorted arrays
  https://github.com/Anuragkr07/DSA/blob/main/Arrays/Misc/merge%202%20sorted%20arrays.cpp
*/

#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&arr, int s, int e) {

    int mid = (s+e)/2;

    int n = mid - s + 1;
    int m = e - mid;

    vector<int>first(n);
    vector<int>second(m);
    
    // divide the arrays into two parts
    
    int k = s;
    for(int i=0; i<n; i++) {
        first[i] = arr[k++];
    }

    k = mid+1;
    for(int i=0; i<m; i++) {
        second[i] = arr[k++];
    }

    // merge 2 sorted arrays      
    int i1 = 0;
    int i2 = 0;
    k = s;

    while(i1 < n && i2 < m) {
        if(first[i1] < second[i2]) {
            arr[k++] = first[i1++];
        }
        else{
            arr[k++] = second[i2++];
        }
    }   

    while(i1 < n) {
        arr[k++] = first[i1++];
    }

    while(i2 < m ) {
        arr[k++] = second[i2++];
    }

    first.clear();
    second.clear();

}

void mergeSort(vector<int>&arr, int s, int e) {

    //base case
    if(s >= e) {
        return;
    }
    
    int mid = (s+e)/2;

     
    mergeSort(arr, s, mid);
    
    mergeSort(arr, mid+1, e);

    merge(arr, s, e);

}

int main() {

    cout<<"Enter the size of the array : ";
    int n;
    cin>>n;
    vector<int>arr;
    cout<<"Enter the elements of the array : ";
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        arr.push_back(ele);
    }

    mergeSort(arr, 0, n-1);

    for(auto i:arr)
    {
        cout<<i<< " ";
    }

    return 0;
}




/*

 TC: O(nlogn)
 SC: O(n)
 Not Inplace 
 Stable

 */