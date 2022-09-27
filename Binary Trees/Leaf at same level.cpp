// Problem Link: https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1

#include<bits/stdc++.h>
using namespace std;

class Node
{
    int data;
    Node* left;
    Node* right;
};


class Solution{
  public:
    /*You are required to complete this method*/
    bool check(Node *root)
    {
        if(!root)
            return true;
        unordered_map<int,Node*>m;
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        int level=1;
        while(!q.empty())
        {
            auto f=q.front();
            q.pop();
            if(f!=NULL)
            {
                if(!f->left && !f->right)
                {
                    m[level]=f;
                    if(m.size()>1)
                        return false;
                }
                
                if(f->left)     q.push(f->left);
                if(f->right)    q.push(f->right);
            }
            else
            {
                level++;
                if(!q.empty())
                q.push(NULL);
            }
        }
        
        
        
        return true;