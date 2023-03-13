class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        int mindiff = INT_MAX;
        for (int i = 0; i < n - 2; i++)
        {
            int s = i + 1, e = n - 1;
            while (s < e)
            {
                int sum = nums[i] + nums[s] + nums[e];
                if (sum == target)
                {
                    return sum;
                }

                if (abs(target - sum) < mindiff)
                {
                    mindiff = abs(target - sum);
                    ans = sum;
                }

                sum < target ? s++ : e--;
            }
        }
        return ans;
    }
};