#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
  
    Node(int data)
    {
       this->data=data;
       left=NULL;
       right=NULL;
    }
};

void inOrder(Node* root)
{
    if(!root)
        return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

/* -------------------------------------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------------------------------------- */


int height(Node * root)
{
    if(!root)
        return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    return 1+max(lh,rh);
}

/* -------------------------------------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------------------------------------- */


int main()
{
    Node* a=new Node(1);
    a->left=new Node(2);
    a->right=new Node(3);
    
    a->left->left=new Node(4);
    a->left->right=new Node(5);
    
    a->right->left=new Node(6);
    a->right->right=new Node(7);
    
    inOrder(a);
    cout<<"\n"<<height(a);
    
    return 0;
}