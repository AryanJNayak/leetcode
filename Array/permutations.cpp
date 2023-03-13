class Solution
{
    void solve(vector<int> nums, int i, vector<vector<int>> &ans)
    {
        if (i >= nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for (int j = i; j < nums.size(); j++)
        {
            swap(nums[i], nums[j]);
            solve(nums, i + 1, ans);
            swap(nums[i], nums[j]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        if (nums.size() == 1)
        {
            ans.push_back(nums);
            return ans;
        }
        solve(nums, 0, ans);
        return ans;
    }
};