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

    vector<double> averageOfLevels(Node* root) {
        vector<double>ans;
        if(!root)
            return ans;
        
        double avg;
        double sum=0;
        int count=0;
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty())
        {
            auto f=q.front();
            q.pop();
            if(f!=NULL)
            {
                count++;
                sum+=f->val;
                if(f->left)     q.push(f->left);
                if(f->right)    q.push(f->right);
            }
            else
            {
                ans.push_back(sum/count);
                count=0;
                sum=0;
                if(!q.empty())
                {
                    q.push(NULL);
                }
            }
        }
        return ans;
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
    
    vector<double>ans=averageOfLevels(root);
    for(auto i: ans)
    {
        cout<<i<<" ";
    }
    
    return 0;
    
}