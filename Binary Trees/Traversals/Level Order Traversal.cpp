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

    void levelOrder(Node* root) {
        if(!root)
            return;
        
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            Node* temp=q.front();
            q.pop();
            if(temp!=NULL)
            {
                
                cout<<temp->val<<" ";
                if(temp->left)  q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }            
            else
            {
                cout<<"\n";
                if(!q.empty()){
                    q.push(NULL);                    
                }                    
            }
            
        }
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
    
    levelOrder(root);
    
    return 0;
    
}