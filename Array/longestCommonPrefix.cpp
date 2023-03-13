class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int n = strs.size();
        if (n == 0)
            return "";
        sort(strs.begin(), strs.end());
        string str1 = strs[0];
        string str2 = strs[n - 1];
        string s = "";
        for (int i = 0; i < min(str1.size(), str2.size()); i++)
        {
            if (str1[i] == str2[i])
            {
                s += str1[i];
            }
            else
            {
                return s;
            }
        }
        return s;
    }
};