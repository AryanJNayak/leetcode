class Solution
{
public:
    int mySqrt(int x)
    {
        long long int ans = 0;
        int si = 0, ei = x;
        long long int mid = si + (ei - si) / 2;
        while (si <= ei)
        {
            long long int square = mid * mid;
            if (square == x)
            {
                return mid;
            }
            if (square < x)
            {
                ans = mid;
                si = mid + 1;
            }
            else
            {
                ei = mid - 1;
            }
            mid = si + (ei - si) / 2;
        }
        return ans;
    }
};