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
 
 
int find(string str, int i, int j)
{
    if(i>j)
        return -1;
    stack<char>stk;
    for(int k=i;k<=j;k++)
    {
        if(str[k]=='(')
            stk.push(str[k]);
        else if(str[k]==')')
        {
            stk.pop();
                
            if(stk.empty())
                return k;
        }
    }
    return -1;
}
 

Node* treeFromString(string str, int s, int e)
{
    if(s>e)
        return NULL;
    
    Node * root = new Node(str[s]-'0');
    int ind=-1;
    if(s+1<=e && str[s+1]=='(')
    {
        ind=find(str,s+1,e);
    }
    if(ind!=-1)
    {
       root->left = treeFromString(str,s+2,ind-1);
       root->right = treeFromString(str,ind+2,e-1); 
    }
    
    
    return root;
}
 

int main()
{
    string str = "1(2(4)(5))(3)";
    Node* root = treeFromString(str, 0, str.length() - 1);
    preOrder(root);
    
    return 0;
}

/*

TC : O(N^2)
SC : O(N)

*/
