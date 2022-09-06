#include<bits/stdc++.h>
using namespace std;

bool isValidParenthesis(string e)
{
    stack<char>s;
    for(int i=0;i<e.length();i++)
    {
        if(e[i]=='('|| e[i]=='{'|| e[i]=='[')
            s.push(e[i]);
        else
        {
            if(!s.empty())
            {
                if(e[i]== ')' && s.top()=='('  || e[i]== '}' && s.top()=='{' || e[i]== ']' && s.top()=='[')
                    s.pop();
                else
                    return false;
            }
            else 
                return false;
        }        
    }
    if(s.empty())
        return true;
    return false;
}

int main()
{
    cout<<isValidParenthesis("[()]{}{[()()]()}")<<endl;
    cout<<isValidParenthesis("[(])")<<endl;
    cout<<isValidParenthesis("[]{}()")<<endl;
    cout<<isValidParenthesis("{[}}()}{}{}{}{}{}{}{}{{}{}}")<<endl;

    return 0;
}
