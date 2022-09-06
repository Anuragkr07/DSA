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

void sortedInsert(stack<int> &s, int x)
{
    if(s.empty() || (!s.empty() && x>s.top()))
    {
        s.push(x);
        return;
    }
        
    int temp=s.top();
    s.pop();
    sortedInsert(s,x);
    s.push(temp);
}

void sortStack(stack<int> &s)
{
    if(s.empty())
        return;
    
    int x=s.top();
    s.pop();
    sortStack(s);
 
    sortedInsert(s,x);
    
}

int main()
{
    stack<int>s;
    s.push(10);
    s.push(15);
    s.push(12);
    s.push(18);
    s.push(16);
    
    cout<<"Stack Before Sorting: "<<endl;
    
    printStack(s);
    
    cout<<"Stack After Sorting: "<<endl;
    sortStack(s);
    
    
    printStack(s);
}