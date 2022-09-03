/*

    Check if a string starts with a given prefix

*/

#include <bits/stdc++.h>
using namespace std;

bool startsWith(string mainStr, string toMatch)
{
    if(mainStr.find(toMatch) == 0)
        return true;
    else
        return false;
}

int main() {
    string str;
    str = "hey how are you";
    if(startsWith(str,"hei"))
        cout<<"true";
    else
        cout<<"false";
    
    
    return 0;
}