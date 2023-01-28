class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string str = s;
        reverse(s.begin(),s.end());
        return s == str;
    }
};