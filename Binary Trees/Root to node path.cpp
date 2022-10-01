// Problem Link : https://www.interviewbit.com/problems/path-to-given-node/

#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool pathExist(TreeNode* root, int x, vector<int>& path)
{
    if(!root)
    return false;
    
    path.push_back(root->val);
    if(root->val==x)
        return true;
    
    if( pathExist(root->left,x,path) || pathExist(root->right,x,path))
    return true;
    
    path.pop_back();
    return false;
} 
 
vector<int> solve(TreeNode* A, int B) {
    vector<int>arr;
    if(!A)
        return arr;
    pathExist(A,B,arr);
    return arr;
}
