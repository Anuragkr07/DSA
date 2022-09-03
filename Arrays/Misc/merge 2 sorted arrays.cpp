#include<bits/stdc++.h>
using namespace std;
bool isSorted(vector<int> arr)       
{
    int n=arr.size();
    if (n<=1)
        return true;
 
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] > arr[i])
            return false;
    }
    return true;
}

void merge(vector<int>a1 , vector<int>a2 , vector<int>& a3) 
{
    int n=a1.size();
    int m=a2.size();

    int i = 0, j = 0;
    int k = 0;
    while( i<n && j<m) {
        if(a1[i] < a2[j]){
            a3[k++] = a1[i++];
        }
        else{
            a3[k++] = a2[j++];
        }
    }

    while(i<n) {
        a3[k++] = a1[i++];
    }

    while(j<m) {
        a3[k++] = a2[j++];
    }
}

int main()
{
    int n;
    cout<<"Enter the size of the first array : ";
    cin>>n;
    vector<int>a1;
    cout<<"Enter the elements of the first sorted array : ";
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        a1.push_back(ele);
    }
    if(isSorted(a1)==false)
    {
        cout<<"Array 1 is not sorted !! ";
        exit(0);
    }    
    
    int m;
    cout<<"Enter the size of the second array : ";
    cin>>m;
    vector<int>a2;
    cout<<"Enter the elements of the second sorted array : ";
    for(int i=0;i<m;i++)
    {
        int ele;
        cin>>ele;
        a2.push_back(ele);
    }
    if(isSorted(a2)==false)
    {
        cout<<"Array 2 is not sorted !!";
        exit(0);   
    }
    
    vector<int>a3(a1.size()+a2.size());
    
    merge(a1,a2,a3);
    cout<<"The merged array is :"<<endl;
    for(auto i:a3)
    {
        cout<<i<<" ";
    } 
    
    return 0;         
}