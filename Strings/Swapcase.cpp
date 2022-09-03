#include<bits/stdc++.h>
using namespace std;

char change_case (char c) {
    if (isupper(c)) 
        return tolower(c); 
    else
        return toupper(c); 
}

int main() {
    string str;
    str = "hEllo world";
    transform(str.begin(), str.end(), str.begin(), change_case);
    cout << str;
    return 0;
}

// O/p: HeLLO WORLD


/*
  in python:
txt = "hEllo world"
txt = txt.swapcase()
print(txt)
O/p: HeLLO WORLD
*/