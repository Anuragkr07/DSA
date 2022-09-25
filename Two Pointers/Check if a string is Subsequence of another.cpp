// Problem Link : https://leetcode.com/problems/is-subsequence/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m=s.length();
        int n=t.length();
        if(m>n)
            return false;
        int i=0,j=0;
        while(i<m && j<n)
        {
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else
                j++;
                
        }
        if(i==m)
            return true;
        return false;
    }
};