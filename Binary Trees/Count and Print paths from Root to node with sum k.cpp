// Problem Link : https://practice.geeksforgeeks.org/problems/paths-from-root-with-a-specified-sum/1


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

void printIt(vector<int>path)
{
    for(int j=0;j<path.size();j++)
    {
        cout<<path[j]<<" ";
    }
    cout<<"\n";
}

void solve(Node* root, int k, int &count, vector<int>& path, int &sum)
{
    if(!root)   return;
    path.push_back(root->val);
    sum+=root->val;
    if(sum==k)
    {
        count++;
        printIt(path);
    }
    
    
    if(root->left)  solve(root->left, k, count, path,sum);
    if(root->right) solve(root->right, k, count, path,sum);
    
    path.pop_back();
    sum-=root->val;
}

int printPaths(Node* root, int k)
{
    int count=0;
    vector<int>path;
    int sum=0;
    solve(root,k,count,path,sum);
    return count;
}



int main () 
{ 
    /*          10 
              /   \ 
            28    13 
            /       \ 
           14       15 
          / \      /  \ 
        21   22   23  24       */
        
    Node *root = new Node(10); 
    root->left = new Node(28); 
    root->right = new Node(13); 
  
    root->right->left = new Node(14); 
    root->right->right = new Node(15); 
  
    root->right->left->left = new Node(21); 
    root->right->left->right = new Node(22); 
    root->right->right->left = new Node(23); 
    root->right->right->right = new Node(24); 
  
    int k= 38; 
    int count=printPaths(root, k);
    cout<<"Number of Paths from root to node with sum "<<k<<" : "<<count;
    return 0; 
} 