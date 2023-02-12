class Solution {
    int Bsearch(vector<int>& nums, int s, int e, int target)
    {
        if( s > e ) return -1;
        int mid = s + (e-s) / 2;
        if(nums[mid] == target) return mid;
        if(nums[mid] < target) return  Bsearch(nums,mid+1,e,target);
        else return Bsearch(nums,s,mid-1,target);
    }
public:
    int search(vector<int>& nums, int target) {
        return Bsearch(nums,0,nums.size()-1,target);
    }
};