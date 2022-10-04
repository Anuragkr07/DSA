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
    TreeNode* find(TreeNode* curr)
    {
        TreeNode* pre=curr->left;
        while(pre->right != NULL && pre->right!=curr)
            pre=pre->right;
        return pre;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr=root;
        vector<int>ans;
        while(curr)
        {
            if(curr->left==NULL)
            {
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else
            {
                TreeNode* pre=find(curr);
                if(pre->right == NULL)
                {
                    pre->right=curr;
                    curr=curr->left;
                }
                else
                {
                    pre->right=NULL;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};