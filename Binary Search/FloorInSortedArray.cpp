/*
Given a sorted array arr[] of size N without duplicates, and given a value x. Floor of x is defined as the largest element K in arr[] such that K is smaller than or equal to x. Find the index of K(0-based indexing).


Example 1:
Input:
N = 7, x = 0 
arr[] = {1,2,8,10,11,12,19}
Output: -1
*/
class Solution{
  public:
    int findFloor(vector<long long> v, long long n, long long x){
        int florr = -1;
        int si = 0, ei = n-1;
        while(si <= ei)
        {
            int mid=si+(ei-si)/2;
            if(v[mid] == x) return mid;
            if(v[mid] < x) { florr = mid; si = mid+1;}
            else if (v[mid] > x) ei = mid - 1;
        }
        return florr;
    }
};