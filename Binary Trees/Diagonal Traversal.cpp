// Problem Link: https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

vector<int> diagonal(Node *root)
{
   vector<int>ans;
   if(!root)
    return ans;
   queue<Node*>q;
   q.push(root);
   while(!q.empty())
   {
       Node* f=q.front();
       q.pop();
       while(f)
       {
           ans.push_back(f->data);
           if(f->left)  q.push(f->left);
           f=f->right;
       }
   }
   return ans;
}