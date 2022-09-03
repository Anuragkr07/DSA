/*

 Alternative for Python's split function 

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    string s="hello world";
    vector<string> v;
    string word="";
    for(auto i: s)
    {
        if(i==' ')
        {
            v.push_back(word);
            word="";
        }
        else
            word+=i;
    }
    v.push_back(word);
    
    for(auto i:v)
    {
        cout<<i<<" ";
    }

    return 0;
}




/*
python code
txt = "welcome to the jungle"
x = txt.split()
print(x)
O/p: ['welcome', 'to', 'the', 'jungle']
*/