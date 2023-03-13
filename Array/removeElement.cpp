class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int n = nums.size();
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (val != nums[i])
            {
                swap(nums[j], nums[i]);
                j++;
            }
        }
        return j;
    }
};