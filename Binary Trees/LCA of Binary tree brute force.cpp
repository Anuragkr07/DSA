// Problem Link : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/ 

#include<bits/stdc++.h>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };



bool pathExist(TreeNode* root, TreeNode* x, vector<TreeNode*>& path)
{
    if(!root)
    return false;
    
    path.push_back(root);
    if(root==x)
        return true;
    
    if( pathExist(root->left,x,path) || pathExist(root->right,x,path))
    return true;
    
    path.pop_back();
    return false;
} 

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>path1,path2;
        if ( !pathExist(root,p, path1) || !pathExist(root,q, path2))
          return NULL;
        int i=0,j=0;
        while(i<path1.size() && j<path2.size())
        {
            if(path1[i]==path2[j])
            {
                i++;
                j++;
            }
            else
                break;
        }
        return path1[i-1];
    }
