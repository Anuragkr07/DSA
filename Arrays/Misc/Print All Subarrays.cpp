/*
Given an array.
The task is to store it as a vector of vector and print it.

Example: 
arr=[-1,4,7,2]

Output : -1 
         -1 4
         -1 4 7
         -1 4 7 2
          4 
          4 7
          4 7 2
          7
          7 2
          2
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>arr={-1,4,7,2};
    int n=arr.size();
    
    vector<vector<int>>subArrays;
    
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            vector<int>temp;
            for(int k=i;k<=j;k++)
            {
             temp.push_back(arr[k]);
            }
            subArrays.push_back(temp);
        }
    }
    
    for (int i = 0; i < subArrays.size(); i++) 
    {
        for (int j=0;j<subArrays[i].size();j++)
        {
            cout << subArrays[i][j]<< " ";
        }
        cout << endl;
    }
    return 0;
}


// Tc:O(n)
