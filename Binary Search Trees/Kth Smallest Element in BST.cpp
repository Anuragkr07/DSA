// Problem Link : https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};


class Solution {
  public:
  Node* find(Node* root)
  {
      Node* pre=root->left;
      while(pre->right && pre->right!=root)
        pre=pre->right;
      return pre;
  }
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int K) {
        int cnt=0;
        Node* curr=root;
        while(curr)
        {
            if(!curr->left)
            {
                cnt++;
                if(cnt==K)
                    return curr->data;
                curr=curr->right;
            }
            else
            {
                Node* pred=find(curr);
                if(!pred->right)
                {
                    pred->right=curr;
                    curr=curr->left;
                }
                else
                {
                    pred->right=NULL;
                    cnt++;
                    if(cnt==K)
                        return curr->data;
                    curr=curr->right;
                }
            }
        }
        return -1;
    }
};