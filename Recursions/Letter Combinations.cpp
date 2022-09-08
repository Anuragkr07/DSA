/*
Problem Link : https://leetcode.com/problems/letter-combinations-of-a-phone-number/
*/

class Solution {
    private:
    void solve(string digits, int  i, vector<string>& ans, string output, vector<string> mapping){
        if(i>=digits.length())
        {
            ans.push_back(output);
            return;
        }
        
        int num=digits[i]-'0';
        string val=mapping[num];
        for(int j=0;j<val.length();j++)
        {
            output.push_back(val[j]);
            solve(digits, i+1, ans, output, mapping);
            output.pop_back();
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.length()==0)
            return ans; 
        string output="";
        vector<string>mapping={ "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        solve(digits, 0, ans, output, mapping);
        return ans;
    }
};
