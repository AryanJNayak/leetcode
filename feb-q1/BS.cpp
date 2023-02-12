int Bsearch(vector<int>& nums, int s, int e, int target)
    {
      int mid = (s + e) / 2;
      while(s <= e)
      {
        if(nums[mid] == target) { return mid; }
        else if(nums[mid] < target) { s = mid + 1; }
        else { e = mid - 1; }
        mid = (s + e) /2;
      }
      return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        return Bsearch(nums,0,nums.size()-1,target);
    }