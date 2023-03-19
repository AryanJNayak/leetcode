/*
Input: s = "42"
Output: 42

Input: s = "   -42"
Output: -42
*/
class Solution
{
public:
    int a(string s, int sign, int i, int result)
    {

        // if we reaches end of string or the character is other than digit
        if (i >= s.size() || s[i] < '0' || s[i] > '9')
        {
            return result * sign;
        }

        // store curr digit
        int digit = s[i] - '0';

        /*
        /  we do this task (result * 10 + digit)
        /  if result * 10 will grater then INT_MAX then it will generate run time error
        /  if result * 10 will == INT_MAX and digit is grater then 7 it is also generate run time error
        /  i.e.
        /      INT_MAX = 2147483647
        /      if result > 214748364 and performing result * 10 + digit will be '2147483640 + digit'
        /      is not fit in 32-bit INTEGER
        /  i.e.
        /      INT_MAX = 2147483647
        /      if result == 214748364 and digit > 7 and performing result * 10 + digit will be
        /          '2147483640 + 9'
        /      is not fit in 32-bit INTEGER
        */
        if (result > INT_MAX / 10 || result == INT_MAX / 10 && digit > 7)
        {
            return sign > 0 ? INT_MAX : INT_MIN;
        }

        // same call goes for i+1 index with add new digit in result
        return a(s, sign, i + 1, result * 10 + digit);
    }
    int myAtoi(string s)
    {
        int n = s.size();
        int i = 0;

        // ignoring white spaces
        while (i < n && s[i] == ' ')
            i++;

        // if string is fully white spaces
        if (i == n)
        {
            return 0;
        }

        // store sign
        int sign = 1; // by deafult sign is plus

        // if sign '-' then ans is return as (ans*sign = -ans)
        if (s[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if (s[i] == '+')
        {
            i++;
        }

        // Recursive call
        return a(s, sign, i, 0);
    }
};