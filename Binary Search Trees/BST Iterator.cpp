// Problem Link : https://leetcode.com/problems/binary-search-tree-iterator/

#include <bits/stdc++.h> 
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class BSTIterator {    
public:
    stack<TreeNode*>stk;
    void pushAll(TreeNode* root)
    {
        while(root)
        {
            stk.push(root);
            root=root->left;
        }
    }

    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        auto itr = stk.top();
        stk.pop();
        pushAll(itr->right);
        return itr->val;
    }
    
    bool hasNext() {
        return !stk.empty();
    }

    
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */