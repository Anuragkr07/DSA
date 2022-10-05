// Problem Link : https://practice.geeksforgeeks.org/problems/sum-tree/1

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
  
    Node(int data)
    {
       this->data=data;
       left=NULL;
       right=NULL;
    }
};



class Solution
{
    public:
    pair<bool,int> solve(Node* root)
    {
        if(!root)
        {
            pair<bool,int>p;
            p.first=true;
            p.second=0;
            return p;
        }
        
        if(!root->left && !root->right)
        {
            pair<bool,int>p = make_pair(true,root->data);
            return p;
        }
        
        pair<bool,int>lh=solve(root->left);
        pair<bool,int>rh=solve(root->right);
        
        pair<bool,int>ans=make_pair(false,1e5);
        if(lh.first && rh.first && (lh.second+rh.second==root->data))
        {
            ans=make_pair(true,2*root->data);
        }
        return ans;
        
    }
    
    bool isSumTree(Node* root)
    {
         return solve(root).first;    
    }
};