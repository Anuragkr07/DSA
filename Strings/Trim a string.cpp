#include <bits/stdc++.h>
using namespace std;

string removeSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

int main()
{
    
    string s = " hello world ";
    s=removeSpaces(s);
    cout<<s;

    return 0;
}

// 



/*
Input 1: " hello world "
Op: "helloworld"

Input 2 = "     ban ana     "
Output: "banana"

*/