class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> spiral;
        int top = 0, bottom = n - 1, left = 0, right = m - 1, cnt = 1, total = m * n;

        while (cnt <= total)
        {
            for (int i = left; cnt <= total && i <= right; i++)
            {
                spiral.push_back(matrix[top][i]);
                cnt++;
            }
            top++;

            for (int i = top; cnt <= total && i <= bottom; i++)
            {
                spiral.push_back(matrix[i][right]);
                cnt++;
            }
            right--;

            for (int i = right; cnt <= total && i >= left; i--)
            {
                spiral.push_back(matrix[bottom][i]);
                cnt++;
            }
            bottom--;

            for (int i = bottom; cnt <= total && i >= top; i--)
            {
                spiral.push_back(matrix[i][left]);
                cnt++;
            }
            left++;
        }
        return spiral;
    }
};