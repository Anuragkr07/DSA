#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int val;
        Node* right;
        Node* left;
  
  
        Node(int val)
        {
            this->val=val;
            left=NULL;
            right=NULL;
        }
};


void preOrder(Node *root)
{
    if(root)
    {
        cout<<root->val<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node *root)
{
    if(root)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->val<<" ";
    }
}

void inOrder(Node *root)
{
    if(root)
    {
        inOrder(root->left);
        cout<<root->val<<" ";
        inOrder(root->right);
    }
}

int main()
{
    Node* root = new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    
    cout<<"Pre Order Traversal : ";
    preOrder(root);
    cout<<endl;
    cout<<"Post Order Traversal : ";
    postOrder(root);
    cout<<endl;
    cout<<"In Order Traversal : ";
    inOrder(root);
    
    return 0;
}