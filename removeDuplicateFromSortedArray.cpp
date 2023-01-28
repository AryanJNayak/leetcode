class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int pos = 0;
       nums[pos++] = nums[0];
       for(int i=1; i<nums.size(); i++)
       {
           if(nums[i] > nums[pos-1])
           {
               nums[pos++] = nums[i];
           }
       }
       return pos;
    }
};
