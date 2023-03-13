class Solution
{
    void solve(string digits, string s, int i, vector<string> &ans, const string maping[10])
    {
        if (i == digits.size())
        {
            ans.push_back(s);
            return;
        }
        int num = digits[i] - '0';
        string val = maping[num];
        for (int j = 0; j < val.size(); j++)
        {
            s.push_back(val[j]);
            solve(digits, s, i + 1, ans, maping);
            s.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        string maping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string s = "";
        if (digits.size() == 0)
        {
            return ans;
        }
        int i = 0;
        solve(digits, s, i, ans, maping);
        return ans;
    }
};