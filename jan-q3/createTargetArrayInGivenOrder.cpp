class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> ans(nums.size()-nums.size(),0);
        for(int i = 0; i<nums.size(); i++)
        {
            
            ans.insert(ans.begin()+(index[i]) , nums[i]);
        }
        return ans;
    }
};