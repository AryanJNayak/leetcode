class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        int x = 0;
        for(int i=0; i<n; i++)
        {
            x = x + nums[i];
            ans.push_back(x);
        }
        return ans;
    }
};