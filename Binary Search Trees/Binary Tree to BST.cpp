// Problem Link : https://practice.geeksforgeeks.org/problems/binary-tree-to-bst/1

#include<bits/stdc++.h>
using namespace std;


struct Node{
    int data;
    Node* left=NULL;
    Node* right=NULL;
};



class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    void inorder(Node* root, vector<int>& temp)
    {
        if(root)
        {
            inorder(root->left,temp);
            temp.push_back(root->data);
            inorder(root->right,temp);
        }
    }
    
    void inordertoBst(int &i , Node* &root , vector<int> &temp)
    {
        if(!root)
            return ;
        
        inordertoBst(i,root->left,temp);
        
        root->data=temp[i++];
        
        inordertoBst(i,root->right,temp);
    }
    
    Node *binaryTreeToBST (Node *root)
    {
        vector<int>temp;
        inorder(root,temp);
        sort(temp.begin(),temp.end());
        int i=0;
        inordertoBst(i,root,temp);
        return root;
    }
};

