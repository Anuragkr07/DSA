// Problem Link : https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1

#include<bits/stdc++.h>
using namespace std;


struct Node{
    int data;
    Node* left=NULL;
    Node* right=NULL;
};


int solve(Node*root, int l , int h, int &count)
{
    if(!root)
        return 0;
    
    if(root->data >=l && root->data<=h)
    {
        count++;
        return solve(root->left,l,h,count) + solve(root->right,l,h,count);
    }
    else if(root->data <l)
        return solve(root->right,l,h,count);
    else
        return solve(root->left,l,h,count);
        
}

    int getCount(Node *root, int l, int h)
    {
        int count=0;
        solve(root,l,h,count);
        return count;
    }