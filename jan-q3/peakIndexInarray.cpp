class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int si = 0, ei = arr.size() - 1;
        int mid  = 0;
        int ans ;
          while(si < ei){
               mid  = si + (ei-si) / 2;
        if(arr[mid] < arr[mid+1]) {si = mid+1;}
        
        else { ei = mid; }
        // mid  = si + (ei-si) / 2;
    } 
  return si;
    }
};
