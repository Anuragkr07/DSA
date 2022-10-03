// Problem Link : https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

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
 

class BSTIterator {    
public:
    stack<TreeNode*>stk;
    bool rev=true;

    void pushAll(TreeNode* root)
    {
            while(root)
            {
                stk.push(root);
                if(rev==true)
                    root=root->right;
                else
                    root=root->left;
            }        
    }

    BSTIterator(TreeNode* root, bool isRev) {
        rev = isRev;
        pushAll(root);
    }
    
    int next() {
        auto itr = stk.top();
        stk.pop();
        if(!rev) pushAll(itr->right);
        else pushAll(itr->left);
        return itr->val;
    }
    
    bool hasNext() {
        return !stk.empty();
    }

    
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator* l =new BSTIterator(root,false);
        BSTIterator* r = new BSTIterator(root,true);

        int i=l->next();
        int j=r->next();    // r->before()
        while(i<j)
        {
            if(i+j == k)
                return true;
            else if(i+j<k)
                i= l->next();
            else
                j=r->next();           // r->before()
        }
        return false;
    }
};