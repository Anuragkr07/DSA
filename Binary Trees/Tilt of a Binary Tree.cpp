// Problem Link : https://leetcode.com/problems/binary-tree-tilt/description/


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
int tilt=0;
    int solve(TreeNode* root)
    {
        if(!root)   return 0;

        int a=solve(root->left);
        int b=solve(root->right);

        tilt+= abs(b-a);
        return a+b+ root->val;
    }
    int findTilt(TreeNode* root) {
        solve(root);
        return tilt;
    }
};
