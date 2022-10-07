// Problem Link : https://leetcode.com/problems/spiral-matrix/description/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n=matrix[0].size();

        int total=m*n;
        int count=0;
        vector<int>ans;

        int startingRow = 0;
        int endingRow = m-1;
        int startingCol = 0;
        int endingCol = n-1;

        while(count < total)
        {

            // starting row print
            for(int i = startingCol; count<total && i<=endingCol; i++)
            {
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++;

            // ending col print
            for(int i= startingRow; count<total && i<= endingRow; i++)
            {
                ans.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--;

            // ending row print
            for(int i= endingCol; count<total && i>=startingCol; i--)
            {
                ans.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--;

            // starting Col print
            for(int i=endingRow; count<total && i>=startingRow; i--)
            {
                ans.push_back(matrix[i][startingCol]);
                count++;
            }
            startingCol++;

        }
        return ans;
    }
};

// TC : O(m*n)