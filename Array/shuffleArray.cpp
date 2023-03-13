class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        int size = nums.size();
        vector<int> ans;

        int x = 0;
        for (int i = 0; (x < size) && (n < size) && (i < size); i++)
        {
            ans.push_back(nums[x++]);
            ans.push_back(nums[n++]);
        }

        return ans;
    }
};