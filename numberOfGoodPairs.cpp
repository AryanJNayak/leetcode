class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int cnt = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            int j = i+1;
            while(j<nums.size())
            {
                if( i<j && nums[i] == nums[j] )
                {
                    cnt++;
                }
                j++;
            }
        }
        return cnt;
    }
};