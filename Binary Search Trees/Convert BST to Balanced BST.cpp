// Problem Link : https://leetcode.com/problems/balance-a-binary-search-tree/description/

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

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& temp)
    {
        if(!root)
        return;

        inorder(root->left,temp);
        temp.push_back(root->val);
        inorder(root->right,temp);
    }

    TreeNode* balance(int i, int j, vector<int>temp)
    {
        if(i>j)
        return NULL;

        int mid=j-(j-i)/2;
        TreeNode* a = new TreeNode(temp[mid]);
        a->left=balance(i,mid-1,temp);
        a->right=balance(mid+1,j,temp);

        return a;
    } 

    TreeNode* balanceBST(TreeNode* root) {
        vector<int>temp;
        inorder(root,temp);
        return balance(0,temp.size()-1,temp);
    }
};
