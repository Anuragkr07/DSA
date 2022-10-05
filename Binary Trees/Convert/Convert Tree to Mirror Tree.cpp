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
        Node()
        {
            
            left=NULL;
            right=NULL;
        }
        
};


void inOrder(Node *root)
{
    if(root)
    {
        inOrder(root->left);
        cout<<root->val<<" ";
        inOrder(root->right);
    }
}

void mirrorTree(Node* root)
{
    // Base Case
    if (root == NULL)
        return ;
    Node* t = new Node();
    t=root->left;
    root->left = root->right;
    root->right = t;
 
    if (root->left)
        mirrorTree(root->left);
    if (root->right)
        mirrorTree(root->right);
   
  return;
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

    cout<<"In Order Traversal : ";
    inOrder(root);
    mirrorTree(root);
    cout<<"\n";
    cout<<"Mirror In Order Traversal : ";
    inOrder(root);
    
    return 0;
}