/*
Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

The test cases are generated so that there will be an answer.

 

Example 1:
Input: nums = [1,2,5,9], threshold = 6
Output: 5
*/

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = 1e6, mid, sum;

        while (left<right) {
            mid=(left+right)/2;
            sum = 0;
            
            for (int e:nums) sum += (e+mid-1)/mid;
            
            if (sum>threshold) left=mid+1;
            
            else    right=mid;
        }
        return left;
    }
};