// Problem Link : https://practice.geeksforgeeks.org/problems/minimum-element-in-bst/1

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left=NULL;
    Node* right=NULL;

};

int minValue(Node* root) {
    // Code here
    if(!root)
        return -1;
    if(!root->left)
        return root->data;
    else 
        return minValue(root->left);
}