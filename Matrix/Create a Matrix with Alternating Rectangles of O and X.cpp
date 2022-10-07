#include<bits/stdc++.h>
using namespace std;

void alternate(vector<vector<int>>& v, int m, int n)
{
    int total = m*n;
    int count=0;
    
    int startRow=0, endingRow=m-1;
    int startCol=0, endingCol=n-1;
    int insert = 1;
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
        
        for(int i=endingRow; count<total && i>=startRow; i++)
        {
            v[i][endingCol] = insert;
            count++;
        }
        
        if(insert == 1) insert =0;
        else insert =1;
    }
}

int main()
{
    int m=5,n=5;
    vector<vector<int>>v(m , vector<int>(n,-1));
    alternate(v,m,n);
    cout<<v.size();
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