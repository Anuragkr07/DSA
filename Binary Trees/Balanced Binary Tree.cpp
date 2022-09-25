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

// Function to check if tree is balanced

int height(Node * root,int &flag)
{
    if(!root)
        return 0;
    int lh=height(root->left,flag);
    int rh=height(root->right,flag);

   // if(lh==-1 && rh==-1)  return -1;
    if( abs(lh-rh) > 1 ) flag=0;
    return 1+max(lh,rh);
}
    

bool isBalanced(Node *root)
{
   int flag=1;
   height(root,flag);
   return flag;      
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
    if(balanced(a)==1)
        cout<<"\n Balanced Tree";
    else
        cout<<"\nNot Balanced Tree";
    
    return 0;
}
