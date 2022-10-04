// Problem Link : https://practice.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1

#include<bits/stdc++.h>
using namespace std;


struct Node {
int data;
Node * right= NULL;
Node * left= NULL;
};

/*You are required to complete below method */
void pushAll(Node* root, unordered_map<int,int> & m)
{
    if(root)
    {
        pushAll(root->left,m);
        m[root->data]++;
        pushAll(root->right,m);
    }
}

bool check(Node* root, unordered_map<int,int>& m)
{
    if(!root)
        return false;
    if(!root->left && !root->right)
    {
        int prev = root->data - 1;
        int next = root->data + 1;
        
        if(m[prev]>0 && m[next] >0)
            return true;
    }
    return check(root->left,m) || check(root->right,m);
}

bool isDeadEnd(Node *root)
{
    if(!root)
        return false;
    unordered_map<int,int>m;
    m[0]++;
    pushAll(root,m);
    return check(root,m);
}