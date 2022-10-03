// Problem Link : https://leetcode.com/problems/minimum-depth-of-binary-tree/description/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


    int minDepth(TreeNode* root) {
        if(!root)  return 0;
        if(!root->left && !root->right)  return 1;

        else if(!root->left) return 1+minDepth(root->right);
        else if(!root->right) return 1+minDepth(root->left);
        else
            return 1 + min( minDepth(root->right) , minDepth(root->left) );

    }