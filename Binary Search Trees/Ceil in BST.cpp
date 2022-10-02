// Problem Link : https://www.codingninjas.com/codestudio/problems/ceil-from-bst_920464?leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

    template <typename T>
    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };


int findCeil(BinaryTreeNode<int> *root, int x){
    // Write your code here.
    if(!root)
        return -1;
    int ceil=-1;
    while(root)
    {
        if(root->data==x)
        {
            return root->data;
        }
        else if(root->data <x)
            root=root->right;
        else
        {
            ceil=root->data;
            root=root->left;
        }
    }
    return ceil;
}