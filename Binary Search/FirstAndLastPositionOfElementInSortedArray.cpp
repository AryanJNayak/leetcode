/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/
class Solution {
public:
    
vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int fst = -1, lst = -1;
        int s = 0, e = n-1;
        while(s <= e)
        {
            int mid = (e+s) / 2;
            if(nums[mid] == target) { fst=mid; e = mid - 1;}
            else if(nums[mid] < target) { s = mid+1; }
            else { e = mid-1; }
        }
        s = 0, e = n-1;
        while(s <= e)
        {
            int mid = (e+s) / 2;
            if(nums[mid] == target) { lst=mid; s = mid + 1;}
            else if(nums[mid] < target) { s = mid+1; }
            else { e = mid-1; }
        }

        return {fst,lst};
    }
};