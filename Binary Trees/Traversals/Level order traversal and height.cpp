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

    int maxDepth(Node* root) {
        if (!root) return 0;
        queue<Node*> q;
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();
                cout<<node->data<<" ";
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            depth++;
        }
        cout<<endl;
        return depth;
    }

int main()
{
    Node* a=new Node(1);
    a->left=new Node(2);
    a->right=new Node(3);
    
    a->left->left=new Node(4);
    a->left->right=new Node(5);
    
    a->right->left=new Node(6);
    a->right->right=new Node(7);
    

    cout<<maxDepth(a);
    
    
    
    return 0;
}