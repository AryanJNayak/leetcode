class Solution {
public:
int first(vector<int>& arr, int n, int k)
{
   int si = 0, ei = n - 1, ans = -1;
   while (si <= ei)
   {
      int mid = si + (ei - si) / 2;
      if (arr[mid] == k)
      {  ans = mid;
         ei = mid - 1; }
      
       if (arr[mid] < k)
      { si = mid + 1; }
      
       else { ei = mid - 1;   }
   }
   return ans;
}


int last(vector<int>& arr, int n, int k)
{
   int si = 0, ei = n - 1;
   int ans = -1;
   int mid = si + (ei - si) / 2;
    while (si <= ei)
   {      
      if (arr[mid] == k)
      {  ans = mid;
         si = mid + 1; }
      else if (arr[mid] < k) { si = mid + 1; }
      else { ei = mid - 1; }
       mid = si + (ei - si) / 2;
    }
   return ans;
}
    
vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        int x = first(nums,nums.size(),target);
        int y = last(nums,nums.size(),target);
        ans.push_back(x);
        ans.push_back(y);
        return ans;
    }
};