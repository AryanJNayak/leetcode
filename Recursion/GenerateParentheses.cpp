/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]
*/

class Solution {
public:
    void func(int open, int close, int n, string s, vector<string>& ans) {
        //open and close parentheses equal to n
        if(open == close && close == n) {
            //one of the combination is ready
            ans.push_back(s);
            return;
        }

        //open parentheses is still reamaining
        if(open < n) {
            s.push_back('(');
            func(open+1,close,n,s,ans);
            s.pop_back();
        }

        //close parentheses is still needed to be include 
        //because open parentheses is in string 's' and 
        //we make a combinations of well-formed parentheses
        if(close < open) {
            s.push_back(')');
            func(open,close+1,n,s,ans);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        func(0,0,n,"",ans);
        return ans;
    }
};