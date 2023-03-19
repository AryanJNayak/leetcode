/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
*/


//approach 1
class Solution
{
public:
    bool safe(int row, int col, vector<string> &out, int n)
    {
        /*
        /  -> The Only thing which we check is by placing queen at out[row][col] doesn't kill other
        /     placed queen
        /
        /  -  queen can attack 8 direction:
        /
        /         1     2[X]  3[X]        [X] means no need to check
        /          \    |    /            1 = Upper-Left-Diagonal
        /           \   |   /             2 = Up
        /            \  |  /              3 = 1 = Upper-Right-Diagonal
        /             \ | /               4 = Right
        /    8 -------- Q -------- 4[X]   5 = Lower-Right-Diagonal
        /             / | \               6 = Bottom
        /            /  |  \              7 = Lower-Left-Diagonal
        /           /   |   \             8 = Left
        /          /    |    \
        /         7   6[X]  5[X]
        /
        /
        /
        /  ->  after 'col' in 'out' no queen('Q') is placed because we going from 'col = 0' to 'n' so we
        /      not check for queen is present in "Right", "Right-Upper-Diagonal", "Right-Lower-Diagonal"

        /   "In one column only one queen is present"
        /    -  which is tack care by "col+1"[func(col + 1, n, out, ans)]
        /       so no need to check for queen is present in "Bottom-Of_column" , "Up-Of_column"

        / Only check for left side of 'out'["Upper-Left-Diagonal","Lower-Left-Diagonal","Left"]
        */

        // row-- col--   "Upper-Left-Diagonal"
        int i = row, j = col;
        while (i >= 0 && j >= 0)
        {
            if (out[i][j] == 'Q')
            {
                return false;
            }
            i--;
            j--;
        }

        // row col--  "Left"
        i = row, j = col;
        while (j >= 0)
        {
            if (out[i][j] == 'Q')
            {
                return false;
            }
            j--;
        }

        // row++ col--  "Lower-Left-Diagonal"
        i = row, j = col;
        while (i < n && j >= 0)
        {
            if (out[i][j] == 'Q')
            {
                return false;
            }
            j--;
            i++;
        }

        return true;
    }
    void func(int col, int n, vector<string> out, vector<vector<string>> &ans)
    {
        // IF 'col' touches 'n'
        if (col == n)
        {
            // we have one answer is ready as 'out'
            ans.push_back(out);
            return;
        }

        // Every row place Queen
        for (int row = 0; row < n; row++)
        {
            // if by placing 'Q' in out[row][col] not broke any "rule"
            if (safe(row, col, out, n))
            {
                // then place at out[row][col]
                out[row][col] = 'Q';

                // and try for next 'col'
                func(col + 1, n, out, ans);

                // restore line:64 to '.'
                out[row][col] = '.'; // back-Track
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        // create ans
        vector<vector<string>> ans;

        /*
        /   'out' consist chess board
        /   i.e. n = 5
        /   out =  . . . . .
        /          . . . . .
        /          . . . . .
        /          . . . . .
        /          . . . . .
        */
        vector<string> out(n, string(n, '.'));

        // get ans
        func(0, n, out, ans);

        return ans;
    }
};







//approach 2
class Solution {
public:

bool safe(int row, int col, vector<string> &out, int n, vector<char>left, vector<char>& ul, 
vector<char>& bl)
{
    //left contain all the qeen which placed in row
    //ul contain all the queen which placed at upper-left-diagonal
    //bl contain all the queen which placed at bottom-left-diagonal
    if(left[row] == 'Q' || ul[ (n-1) + (row-col)] == 'Q' || bl[row+col] == 'Q') {return false;}

    return true;
}

void func(int col, int n, vector<string> out, vector<vector<string>> &ans, vector<char>left,
vector<char>& ul, vector<char>& bl )
{
    //we reaches to the one possible answer
    if (col == n)
    {
        ans.push_back(out);
        return;
    }
    
    //checking for every row
    for (int row = 0; row < n; row++)
    {
        if (safe(row, col, out, n, left,ul,bl))
        {
            //placed queen
            out[row][col] = 'Q';
            left[row] = 'Q';
            ul[ (n-1) + (row-col)] = 'Q';
            bl[row+col] = 'Q';

            func(col + 1, n, out, ans, left, ul, bl);

            //Back-Track
            out[row][col] = '.';
            left[row] = '.';
            ul[ (n-1) + (row-col)] = '.';
            bl[row+col] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;//returnable answer
    vector<string> out(n, string(n,'.'));//store all placed queen to ans

    vector<char> left(n,'.');//hash 'Q' of left
    vector<char> bLD(2*n-1,'.');//hash 'Q' of bottom-left-diagonal
    vector<char> uLD(2*n-1,'.');//hash 'Q' of upper-left-diagonal

    func(0, n, out, ans, left, bLD, uLD);
    return ans;
}
};