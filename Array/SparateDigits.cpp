/*
Example 1:
Input: nums = [13,25,83,77]
Output: [1,3,2,5,8,3,7,7]

Example 2:
Input: nums = [7,1,3,9]
Output: [7,1,3,9]

*/
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        
        //count index of previos degit
        int x = 0;
        
        for(int i = 0; i<nums.size(); i++)
        {
            vector<int>temp;

            //current number
            int num = nums[i];
            
            //denotes size of number i.e. num = 134 then z = 3;
            int z = 0;

            //each number saprated devide by 10 and every time digit's reminder added to the temp
            //i.e. 134 
            // num = 134 temp = {0}  (=>) num = 13 temp = {4}  (=>) num = 1 temp = {4,3}  (=>) num = 0 temp = {4,3,1} 
            while(num > 0)
            {
                int digit = num%10;
                temp.push_back(digit);
                z++;
                num/=10;
            }

            //reverse temp temp = {4,3,1} 
            //rev(temp) = {1,3,4}    
            reverse(temp.begin(),temp.end());

            //insert temp at previous index(x)
            //ans = {1,3,4} z = 3
            ans.insert(ans.begin()+x,temp.begin(),temp.end());
            
            //next time previos index is 3 so insert next temp at 3rd index
            x+=z;
        }
        
        return ans;
    }
};