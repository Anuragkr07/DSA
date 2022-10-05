/*

Problem Link 1 : https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
problem Link 2 : https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1

*/

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
    void flatten(TreeNode* root) {
        auto curr=root;
        while(curr)
        {
            if(curr->left)
            {
                auto pred=curr->left;
                while(pred->right)
                {
                    pred=pred->right;
                }
                pred->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }
    }
};