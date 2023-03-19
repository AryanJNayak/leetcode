/*
Given an integer array nums of unique elements, return all possible
subsets(the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.


Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]
*/

class Solution {
public:
    //ans passed by reference
    void func(int ind, vector<int>& nums, vector<vector<int>>& ans, vector<int> out, int n) {
        if(ind == n) {
            //leaf of recusion tree got a subset
            ans.push_back(out);
            return;
        }

        //if [index] not-picked but ind+1 
        func(ind+1,nums,ans,out,n);
        
        //if [index] picked and ind+1
        out.push_back(nums[ind]);
        func(ind+1,nums,ans,out,n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> out;
        func(0,nums,ans,out,nums.size());
        return ans;
    }
};