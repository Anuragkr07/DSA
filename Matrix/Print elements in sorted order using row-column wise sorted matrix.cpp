// Problem lInk : https://practice.geeksforgeeks.org/problems/sorted-matrix2333/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        priority_queue<int , vector<int> , greater<int>>pq;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                pq.push(Mat[i][j]);
            }
        }
        int r=0,c=0;
        while(!pq.empty())
        {
            Mat[r][c] = pq.top();
            pq.pop();
            c++;
            if(c==N)
            {
                c=0;
                r++;
            }
        }
        return Mat;
    }
};


/*

TC : O(N^2 log(N))
SC : O(N^2)   for min heap of size N*N

*/