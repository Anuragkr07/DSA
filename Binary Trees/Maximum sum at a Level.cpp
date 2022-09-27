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

    int levelOrder(Node* root) {
        if(!root)
            return -1e9;
        
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        int sum=0,maxi=-1e9;
        while(!q.empty())
        {
            Node* temp=q.front();
            q.pop();
            if(temp!=NULL)
            {
                sum+=temp->val;
                if(temp->left)  q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }            
            else
            {
                maxi=max(maxi,sum);
                sum=0;
                if(!q.empty()){
                    q.push(NULL);                    
                }                    
            }
            
        }
        return maxi;
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
    
    cout<<levelOrder(root);
    
    return 0;
    
}