/*
Given a row wise sorted matrix of size R*C where R and C are always odd, find the median of the matrix.


Example 1:
Input:
R = 3, C = 3
M = [[1, 3, 5], 
     [2, 6, 9], 
     [3, 6, 9]]
Output: 5
*/
class Solution{   
public:
    int countMid(vector<int>mat, int val)
    {
        int low = 0, high = mat.size()-1;
        while(low <= high)
        {
            int mid = (low+high)/2;
            if(mat[mid] <= val) low = mid+1;
            else high = mid-1;
        }
        return low;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        int low = 0, high = 2000;
        int n = matrix.size(), m = matrix[0].size();
        
        while(low <= high)
        {
            int mid = (low+high)/2;
            
            int cnt = 0;
            for(int i = 0; i<n; i++){ cnt += countMid(matrix[i],mid); }
            
            if(cnt <= (n*m)/2) low = mid + 1;
            else high = mid - 1;
        }
        
        return low;
    }
};