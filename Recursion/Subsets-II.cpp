/*
Given an integer array nums that may contain duplicates, return all possible 
subsets(the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:
Input: nums = [0]
Output: [[],[0]]
*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;       //to store all susbets
        vector<int> curr;         //to store current individual subset (that we will build)
        sort(nums.begin(),nums.end());      //sort the array so that duplicates are adjacent 
        helper(nums,ans,curr,0);       //we start from index 0
        return ans;
        
    }
    
    void helper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& curr, int idx){
        ans.push_back(curr);       //we include current susbet into final ans
        for(int i=idx;i<nums.size();i++){     //check for all possibilites
            //i>idx for not grtting array out of bound
            if(i>idx &&  nums[i]==nums[i-1]) continue;      //if duplicate then we continue
            curr.push_back(nums[i]);     //we include nums[i] in current subset
            helper(nums,ans,curr,i+1);
            curr.pop_back();         //to get subset without nums[i]
        }
    }
};