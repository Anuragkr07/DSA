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

void pushAll(Node* root, stack<Node*>& stk)
{
    while(root)
    {
        stk.push(root);
        root=root->left;
    }
}


void inorder(Node* root)
{
    if(!root)
    cout<<"No Element !!";
    stack<Node*>stk;
    
    pushAll(root,stk);
    
    while(!stk.empty())
    {
        auto itr=stk.top();
        stk.pop();
        if(itr->right)
        pushAll(itr->right,stk);
        cout<<itr->val<<" ";
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

    
    inorder(root);
    
    
    return 0;
}