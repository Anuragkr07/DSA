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


    void bottomView(Node *root)
    {
        vector <int> v;
        if (root==NULL){
            return;
        }
       
        queue <pair<Node*,int>> q; //Node , line number
        q.push({root,0});
        map<int,int> m;  //line number, data
       
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            Node *temp=it.first;
            int line=it.second;
           
            if(m.find(line)==m.end())
                m[line]=temp->val;
           
            if (temp->left)  q.push({temp->left,line-1});
            if (temp->right) q.push({temp->right,line+1});

           
        }
       
        for (auto x:m){
           cout<<x.second<<" ";
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

    
    bottomView(root);
    
    return 0;
}