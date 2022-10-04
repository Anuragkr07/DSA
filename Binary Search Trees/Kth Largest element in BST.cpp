// Problem Link : https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1


#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};


class Solution
{
    public:
    
    Node* find(Node* root)
    {
        Node* succ=root->right;
        while(succ->left && succ->left!=root)
            succ=succ->left;
        return succ;
    }
    
    int kthLargest(Node *root, int K)
    {
        int cnt=0;
        Node* curr=root;
        while(curr)
        {
            if(!curr->right)
            {
                cnt++;
                if(cnt==K)
                    return curr->data;
                curr=curr->left;
            }
            else
            {
                Node* succ=find(curr);
                if(!succ->left)
                {
                    succ->left=curr;
                    curr=curr->right;
                }
                else
                {
                    succ->left=NULL;
                    cnt++;
                    if(cnt==K)
                        return curr->data;
                    curr=curr->left;
                }
            }
        }
        return -1;
    }
};