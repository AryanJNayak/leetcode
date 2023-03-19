/*
Given an integer x, find the square root of x. If x is not a perfect square, then return floor(√x)

Example 1:
Input:
x = 5
Output: 2
*/
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        if(x<=1) return x;
        long long int low = 0, high = x;
        long long int ans = 1;
        while(low<=high)
        {
            long long int mid = (low+high)/2;
            if(mid*mid == x) return mid;
            if( (mid*mid) < x  ) { ans = mid; low = mid+1; }
            else { high = mid - 1; }
        }
        return ans;
    }
};