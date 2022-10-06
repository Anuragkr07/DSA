// Problem Link : https://www.geeksforgeeks.org/print-k-sum-paths-binary-tree/

#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int val;
        Node* right;
        Node* left;
  
  
        Node(int val)
        {
            this->val=val;
            left=NULL;
            right=NULL;
        }
};

void printPath(vector<int>path, int i)
{
    for(int j=i;j<path.size();j++)
    {
        cout<<path[j]<<" ";
    }
    cout<<"\n";
}


void solve(Node* root, int k, int &count, vector<int>&path)
{
    if(!root)   return;
    path.push_back(root->val);
    
    if(root->left)  solve(root->left,k,count,path);
    if(root->right) solve(root->right,k,count,path);
    
    int sum=0;
    int n=path.size();
    for(int i=n-1;i>=0;i--)
    {
        sum+=path[i];
        if(sum==k)
        {
            count++;
            printPath(path,i);
        }
    }
    path.pop_back();
}


int kSumPaths(Node* root, int k)
{
    int count=0;
    vector<int>paths;
    solve(root,k,count,paths);
    return count;
}

int main()
{
    Node* root = new Node(1);
    root->left=new Node(3);
    root->right=new Node(-1);
    root->left->left=new Node(2);
    root->left->right=new Node(1);
    root->left->right->left = new Node(1);
    root->right->left=new Node(4);
    root->right->right=new Node(5);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right->right = new Node(6);
    
    int k=5;
    int count = kSumPaths(root,k);
    cout<<"Number of paths with sum equal to k is : "<< count;
    
    return 0;
}


/*

TC: O(n*h*h) as maximum size of path vector can be h 
SC: O(h)

 */ 