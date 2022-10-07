// Problem Link : https://www.geeksforgeeks.org/create-a-matrix-with-alternating-rectangles-of-0-and-x/

#include<bits/stdc++.h>
using namespace std;

void alternate(vector<vector<char>>& v, int m, int n)
{
    int total = m*n;
    int count=0;
    
    int startRow=0, endingRow=m-1;
    int startCol=0, endingCol=n-1;
    int insert = 'X';
    while(count<total)
    {
        for(int i=startCol; count<total && i<=endingCol; i++)
        {
            v[startRow][i] = insert;
            count++;
        }
        startRow++;
        
        for(int i=startRow; count<total && i<=endingRow; i++)
        {
            v[i][endingCol] = insert;
            count++;
        }
        endingCol--;
        
        for(int i=endingCol; count<total && i>=startCol; i--)
        {
            v[endingRow][i] = insert;
            count++;
        }
        endingRow--;
        
        for(int i=endingRow; count<total && i>=startRow; i--)
        {
            v[i][startCol] = insert;
            count++;
        }
        startCol++;
        
        if(insert == 'X') insert ='O';
        else insert ='X';
    }
}

int main()
{
    int m=6,n=7;
    vector<vector<char>>v(m , vector<char>(n,'$'));
    alternate(v,m,n);
    cout<<v.size()<<" "<<v[0].size()<<"\n\n";
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    
    return 0;
}
