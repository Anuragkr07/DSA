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

void postOrderIterative(Node* root)
{
    if (!root)
        return;
 
    stack<Node *> s1, s2;
 
    // push root to first stack
    s1.push(root);
    
 
    // Run while first stack is not empty
    while (!s1.empty()) {
        // Pop an item from s1 and push it to s2
        Node* temp = s1.top();
        s1.pop();
        s2.push(temp);
 
        // Push left and right children
        // of removed item to s1
        if (temp->left)
            s1.push(temp->left);
        if (temp->right)
            s1.push(temp->right);
    }
    
    // Print all elements of second stack
    while (!s2.empty()) {
        Node* temp = s2.top();
        s2.pop();
        cout << temp->data << " ";
    }
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
    
    postOrderIterative(a);
    
    return 0;
}