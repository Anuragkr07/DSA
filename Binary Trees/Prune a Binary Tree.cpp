// Problem Link : https://leetcode.com/problems/binary-tree-pruning/description/


#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    int prune(TreeNode* root)
    {
        if(!root)   return 0;
        if(!root->left && !root->right)
        {
            return root->val;
        }

        int leftSubtree= prune(root->left);
        int rightSubtree= prune(root->right);

        if(leftSubtree==0)
            root->left=NULL;
        if(rightSubtree==0)
            root->right=NULL;
        if( leftSubtree + rightSubtree + root->val < 1 )
            return 0;

        return 1;

    }
    TreeNode* pruneTree(TreeNode* root) {
        if(prune(root)==0)
            return NULL;
        return root;

    }
};