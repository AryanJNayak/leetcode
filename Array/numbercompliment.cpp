class Solution
{
public:
    int findComplement(int num)
    {
        int x = num;
        int mask = 0;
        while (x != 0)
        {
            x = x >> 1;
            mask = (mask << 1) | 1;
        }
        int ans = (~num) & mask;
        return ans;
    }
};
