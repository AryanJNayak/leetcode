/*
Example 1:
Input: nums1 = [1,2,3], nums2 = [2,4]
Output: 2

Example 2:
Input: nums1 = [1,2,3,6], nums2 = [2,3,4,5]
Output: 2
*/
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        //in case of first element of second array is grater then last elemnt of first element then no need to check for entire array and vice versa
        if(nums1[n-1] < nums2[0] || nums2[m-1] < nums1[0]) { return -1; }
        
        int i = 0, j = 0;
        while(i<n && j<m)
        {
            //two element common
            if(nums1[i] == nums2[j]) return nums1[i];
            
            //traverse array1
            else if(nums1[i] < nums2[j]) i++;

            //traverse array2 
            else j++;
        }
        
        return -1;
    }
};