class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i+1<n; i++)
        {
            int sum1 = nums[i]+nums[i+1];
            for(int j = i+1; j+1<n; j++)
            {
                int sum2 = nums[j]+nums[j+1];
                if(sum1 == sum2) return true;
            }
        }
        return false;
    }
};