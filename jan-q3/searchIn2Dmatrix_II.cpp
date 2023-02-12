class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        int rowidx = 0;
        int colidx = col - 1;
        
        while(rowidx < row && colidx >= 0)
        {
            int ele = matrix[rowidx][colidx];
            if(ele == target) { return 1; }
            if(ele < target) { rowidx++; }
            else { colidx--; }
        }
      return 0;
    }
};