// Problem Link : https://leetcode.com/problems/validate-binary-search-tree/description/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool check(TreeNode* root, long mini, long maxi)
    {
        if(!root) return true;

        if( root->val>=maxi || root->val<= mini )
            return false;
        else
            return check(root->left,mini,root->val) && check(root->right,root->val,maxi) ;
    }

    bool isValidBST(TreeNode* root) {
        return check(root,LONG_MIN,LONG_MAX);
    }