/*
Given a boolean 2D array of n x m dimensions where each row is sorted. Find the 0-based index of the first row that has the maximum number of 1's.

Example 1:
Input: 
N = 4 , M = 4
Arr[][] = {{0, 1, 1, 1},
           {0, 0, 1, 1},
           {1, 1, 1, 1},
           {0, 0, 0, 0}}

Output: 2
*/

class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int ans = -1;
	    int maxcnt = INT_MIN;
	    for(int i = 0; i<n; i++) {
	        int cnt = 0;
	        for(int j = 0; j<m; j++) {
	            if(arr[i][j] == 1) cnt++; 
	        }
	        if(cnt > maxcnt && cnt != 0) {ans = i; maxcnt = cnt;}
	    }
	    return ans;
	}

};