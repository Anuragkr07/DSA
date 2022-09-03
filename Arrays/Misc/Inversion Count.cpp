/*

Count the inversions in the given array.
Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j
Sample Test Case:
A: [3, 5, 6, 9, 1, 2, 7, 8]
Inversions: 10
Explanation: (3,1), (3,2), (5,1), (5,2), (6,1), (6,2), (9,1), (9,2), (9,7), (9,8)

*/

// Pre req: Merge Sort
// Link: https://github.com/Anuragkr07/DSA/blob/main/Arrays/Sorting/Merge%20Sort.cpp


#include<bits/stdc++.h>
using namespace std;

long long merge(vector<int>&arr, int s, int e) {
    long long inv=0;

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
        if(first[i1] <= second[i2]) {
            arr[k++] = first[i1++];
        }
        else{
            arr[k] = second[i2];
            inv += n - i1;
            k++;
            i2++;
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
    return inv;

}

long long mergeSort(vector<int>&arr, int s, int e) {

    //base case
    if(s >= e) {
        return 0;
    }
    
    int mid = (s+e)/2;
    long long inv=0;

     
    inv+=mergeSort(arr, s, mid);
    
    inv+=mergeSort(arr, mid+1, e);

    inv+=merge(arr, s, e);
    
    return inv;

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

    cout<<mergeSort(arr, 0, n-1)<<endl;
    

    for(auto i:arr)
    {
        cout<<i<< " ";
    }

    return 0;
}



/*

TC: O(nlogn)
SC: O(n)

*/