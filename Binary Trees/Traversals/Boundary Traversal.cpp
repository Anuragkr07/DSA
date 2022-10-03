// Problem Link : https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/0

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

class Solution {
public:
    bool isLeaf(Node* root)
    {
        return !root->left && !root->right;
    }
    
    
    void leftBoundary(Node* temp, vector<int>& ans)
    {
        while(temp)
        {
            if(!isLeaf(temp))  ans.push_back(temp->data);
            if(temp->left)  temp=temp->left;
            else temp=temp->right;
        }
    }
    
    
    void rightBoundary(Node* temp, vector<int>& ans)
    {
        stack<int>stk;
        while(temp)
        {
            if(!isLeaf(temp))  stk.push(temp->data);
            if(temp->right)  temp=temp->right;
            else temp=temp->left;
        }
        while(!stk.empty())
        {
            ans.push_back(stk.top());
            stk.pop();
        }
    }
    
    
    void leaf(Node* root, vector<int>& ans)
    {
        if(isLeaf(root)) 
        {
            ans.push_back(root->data);
            return;
        }
        if(root->left) leaf(root->left,ans);
        if(root->right) leaf(root->right,ans);
    }
    
    
    void addLeaves(Node * root, vector < int > & res) {
        if (isLeaf(root)) {
          res.push_back(root -> data);
          return;
        }
        if (root -> left) addLeaves(root -> left, res);
        if (root -> right) addLeaves(root -> right, res);
    }

    vector <int> boundary(Node *root)
    {
        if(!root) return {};
        vector<int>ans;
        if(!isLeaf(root))  ans.push_back(root->data);
        leftBoundary(root->left,ans);
        leaf(root,ans);
        rightBoundary(root->right,ans);
        
        
        return ans;
    }
};