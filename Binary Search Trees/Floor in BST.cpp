// Problem Link : https://www.codingninjas.com/codestudio/problems/floor-from-bst_920457?leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };


int floorInBST(TreeNode<int> * root, int X)
{
    if(!root)
        return -1;
    int floor=-1;
    while(root)
    {
        if(root->val == X)
            return root->val;
        else if(root->val  > X)
            root=root->left;
        else
        {
            floor=root->val;
            root=root->right;
        }
    }
    return floor;
}