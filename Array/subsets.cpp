class Solution
{
    void solve(vector<int> nums, int idx, vector<int> out, vector<vector<int>> &ans)
    {
        if (idx >= nums.size())
        {
            ans.push_back(out);
            return;
        }

        out.push_back(nums[idx]);
        solve(nums, idx + 1, out, ans);

        out.pop_back();
        solve(nums, idx + 1, out, ans);
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> out;
        if (nums.size() == 1)
        {
            ans.push_back(out);
            ans.push_back(nums);
            return ans;
        }
        int idx = 0;
        solve(nums, idx, out, ans);
        return ans;
    }
};