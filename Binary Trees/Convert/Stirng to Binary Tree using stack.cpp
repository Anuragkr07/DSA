#include <bits/stdc++.h>
using namespace std;
 
class Node {
    public: 
        int data;
        Node *left, *right;
        
        Node (int data)
        {
            this->data=data;
            left=NULL;
            right=NULL;
        }
};


void preOrder(Node* node)
{
    if (node == NULL)
        return;
    cout<<node->data<<" ";
    preOrder(node->left);
    preOrder(node->right);
}


Node* treeFromString(string str)
{
    Node * root = new Node(str[0]-'0');
    stack<Node*>stk;
    for(int i=1;i<str.length();i++)
    {
        if(str[i] == '(')
        {
            stk.push(root);
        }
        else if(str[i] == ')')
        {
            root = stk.top();
            stk.pop();
        }
        else
        {
            Node* temp = new Node( str[i] - '0');
            if(root->left == nullptr)
            {
                root->left=temp;
                root=temp;
            }
            else
            {
                root->right=temp;
                root=temp;
            }
        }
    }
    return root;
}

int main()
{
    string str = "1(2()(4)(5))(3)";
    Node* root= treeFromString(str);
    
    preOrder(root);
    
    return 0;
}