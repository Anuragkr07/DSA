#include<bits/stdc++.h>
using namespace std;

void solve(stack<int>&inputStack, int N, int count)
{
    if(count==N/2)
    {
        inputStack.pop();
        return;
    }
    
    int temp=inputStack.top();
    inputStack.pop();
    
    solve(inputStack,N,count+1);
    inputStack.push(temp);
}

void deleteMiddle(stack<int>&inputStack, int N){
	solve(inputStack,N,0);
   
}

int main()
{
    stack<int>s;
    s.push(21);
    s.push(22);
    s.push(23);
    s.push(24);
    s.push(25);
    
    deleteMiddle(s,s.size());
    
    cout<<"Stack after deleting the middle element: "<<endl;
    while(s.size()>0)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    
    
    return 0;
    
}