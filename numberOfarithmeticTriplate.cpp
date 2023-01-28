class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int cnt = 0;
         set<int>s(nums.begin(),nums.end());
        for(auto i:nums)
        {
            if(s.find(i-diff)!=s.end() && s.find(i-2*diff) != s.end())
            {
                cnt++;
            }
        }
        
        return cnt;
    }
};