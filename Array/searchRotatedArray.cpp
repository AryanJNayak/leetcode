class Solution
{

    int binary(vector<int> &nums, int si, int ei, int target)
    {
        int mid = si + (ei - si) / 2;
        int ans = -1;
        while (si <= ei)
        {
            if (nums[mid] == target)
            {
                ans = mid;
            }
            if (nums[mid] < target)
            {
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

    int piviot(vector<int> &nums)
    {
        int si = 0, ei = nums.size() - 1;
        int mid = si + (ei - si) / 2;
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
        return si;
    }

public:
    int search(vector<int> &nums, int target)
    {
        int ans = -1;
        if (nums[0] == target)
        {
            return 0;
        }
        if (nums[nums.size() - 1] == target)
        {
            return nums.size() - 1;
        }
        int pvt = piviot(nums);
        if (target <= nums[0])
        {
            ans = binary(nums, pvt, nums.size() - 1, target);
        }
        else
        {
            ans = binary(nums, 0, pvt - 1, target);
        }
        return ans;
    }
};