class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans;
        
        for( int i = 0; i<nums.size(); i++ )
        { 
          int cnt  = 0;
          int j = 0;
          
          while( j < nums.size() )
           {
              if(nums[j] < nums[i] && i != j && i<nums.size() && j<nums.size())
              { 
                  cnt++;
                } 
             j++;
          }
          
          ans.push_back(cnt);                
        }
        
        return ans;
    }
};