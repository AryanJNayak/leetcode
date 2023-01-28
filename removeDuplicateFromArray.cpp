class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int j = 0; 
        for(int i = 0; i<n; i++)
         {
            int a = i;
             int x = nums[i];
             nums[j++] = x;
             while(i+1<n && nums[i+1] == x) {i++;}
             if(i-a >=1){nums[j++] = x;}
        }
        
        return j;
    }
};