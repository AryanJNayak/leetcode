/*
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

 

Example 1:
Input: nums = [7,2,5,10,8], k = 2
Output: 18

Example 2:
Input: nums = [1,2,3,4,5], k = 2
Output: 9

*/
class Solution {
public:
    bool possible(vector<int>& arr, int k, int n, int mid)
    {
        int cnt = 1, sum = arr[0];
        for(int i = 1; i<n; i++)
        {
            if(sum + arr[i] > mid) { sum = arr[i]; cnt++; }
            else { sum+=arr[i]; }
            if(cnt > k) return false;
        }
        return sum <= mid;
    }
    
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = INT_MIN, high = 0, ans = -1;
        for(int num:nums ) { low = max(low,num); high+=num; }

        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(possible(nums,k,n,mid) == true) { ans = mid; high = mid - 1; }
            else low = mid + 1;
        }
        return ans;
    }
};