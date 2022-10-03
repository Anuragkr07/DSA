// Problem Link : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/ 

#include<bits/stdc++.h>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };




    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
        return root;

        if(root==p || root==q)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        if(left==NULL)
            return right;
        else if(right==NULL)
            return left;
        else
        return root;
    }
