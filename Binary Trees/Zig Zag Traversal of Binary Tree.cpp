// Problem Link : https://leetcode.com/problems/binary-tree-level-order-traversal/description/


/*
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 */

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)
            return ans;
        
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<int>t;
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            if(temp!=NULL)
            {
                t.push_back(temp->val);
                if(temp->left)  q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }            
            else
            {
                ans.push_back(t);
                t.resize(0);
                if(!q.empty()){
                    q.push(NULL);                    
                }                    
            }
        }
        return ans;
    }
};