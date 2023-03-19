/*
You are given 2 numbers (n , m); the task is to find n√m (nth root of m).
 

Example 1:
Input: n = 2, m = 9
Output: 3
Explanation: 32 = 9
*/
class Solution{
	public:
    long long multi(int mid, int n, int m)
	{
	    long long ans = 1;
	    for(int i = 1; i <= n; i++)
	    {
	        ans  = ans * mid;
	        if(ans>m){break;}
	    }
	    return ans;
	}
	int NthRoot(int n, int m)
	{
	    if(m==1 || n==1) { return m; }
	    int low = 1, high = m;
	    while(low <= high)
	    {
	        int mid = (low+high)/2;
	        long long x = multi(mid,n,m);
	        if(x == m) {return mid;}
	        else if(x < m) { low = mid+1; }
	        else { high = mid-1; }
	    }
	    return -1;
	}  
};