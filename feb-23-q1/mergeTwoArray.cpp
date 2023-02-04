 void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
       if(n >= 1 && m == 0) {return;} 
       if(n == 0 && m > 0) {nums1 = nums2; return;}

      int gap = ceil((float)(n + m) / 2);
  while (gap > 0) {
    int i = 0;
    int j = gap;
    while (j < (n + m)) {
      if (j < n && nums1[i] > nums1[j]) {
        swap(nums1[i], nums1[j]);
      } else if (j >= n && i < n && nums1[i] > nums2[j - n]) {
        swap(nums1[i], nums2[j - n]);
      } else if (j >= n && i >= n && nums2[i - n] > nums2[j - n]) {
        swap(nums2[i - n], nums2[j - n]);
      }
      j++;
      i++;
    }
    if (gap == 1) {
      gap = 0;
    } else {
      gap = ceil((float) gap / 2);
    }
  }
      nums1.insert(nums1.begin()+n,nums2.begin(),nums2.end());
      nums1.resize(m+n);
    }