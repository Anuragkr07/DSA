#include<bits/stdc++.h>
using namespace std;

void printStack(stack<int>stk)
{
    while(!stk.empty())
    {
        cout<<stk.top()<<" ";
        stk.pop();
    }
    cout<<endl;
}

void insertAtBottom(stack<int>& s, int x)
{
    if(s.empty())
    {
        s.push(x);
        return;
    }
    
    int temp=s.top();
    s.pop();
    insertAtBottom(s,x);
    s.push(temp);
}

void revStack(stack<int>& s)
{
    if(s.empty())
    {
        return;
    }
    
    int temp=s.top();
    s.pop();
    revStack(s);
    insertAtBottom(s,temp);
    
}

int main()
{
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(25);
    s.push(32);
    s.push(45);
    
    cout<<"Stack Before Reversing: "<<endl;
    
    printStack(s);
    
    cout<<"Stack After Reversing: "<<endl;
    revStack(s);
    
    
    printStack(s);
}