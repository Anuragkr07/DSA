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
    TreeNode* find(TreeNode* root)
    {
        TreeNode* succ=root->right;
        while(succ->left && succ->left!=root)
            succ=succ->left;
        return succ;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* curr=root;
        while(curr)
        {
            if(!curr->right)
            {
                ans.push_back(curr->val);
                curr=curr->left;
            }
            else
            {
                TreeNode* succ=find(curr);
                if(!succ->left)
                {
                    succ->left=curr;
                    curr=curr->right;
                }
                else
                {
                    succ->left=NULL;
                    ans.push_back(curr->val);
                    curr=curr->left;
                }
            }
        }
        return ans;
    }
};