// Problem Link : https://leetcode.com/problems/insert-into-a-binary-search-tree/description/

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

TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        auto temp=root;
        while(1)
        {
            if(root->val >val)
            {
                if(root->left==NULL) {
                    root->left=new TreeNode(val);
                    break;
                }
                else
                    root=root->left;
            }
            else
            {
                if(root->right==NULL) {
                    root->right=new TreeNode(val);
                    break;
                }
                else
                    root=root->right;
            }
        }
    return temp;
    }