class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int si = 0, ei = nums.size() - 1;
        int mid = si + (ei - si) / 2;
        if (nums[0] < nums[ei])
        {
            return nums[si];
        }
        while (si < ei)
        {
            if (nums[mid] >= nums[0])
            {
                si = mid + 1;
            }
            else
            {
                ei = mid;
            }
            mid = si + (ei - si) / 2;
        }
        return nums[si];
    }
};