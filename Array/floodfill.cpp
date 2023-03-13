class Solution
{
    void solve(vector<vector<int>> &image, int sr, int sc, int color, int oc)
    {
        if (sr >= image.size() or sc >= image[0].size() or sr < 0 or sc < 0 or image[sr][sc] != oc)
        {
            return;
        }

        image[sr][sc] = color;

        solve(image, sr + 1, sc, color, oc);
        solve(image, sr, sc + 1, color, oc);
        solve(image, sr, sc - 1, color, oc);
        solve(image, sr - 1, sc, color, oc);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int oc = image[sr][sc];
        if (oc == color)
            return image;
        solve(image, sr, sc, color, oc);
        return image;
    }
};