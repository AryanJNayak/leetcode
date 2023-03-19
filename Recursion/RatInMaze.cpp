/*
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
*/
class Solution{
        //by writing 'D', 'R', 'U', 'L' code useing s, di, dj is efficient way
        string s = "DLRU";
        int di[4] = {1, 0, 0,-1};
        int dj[4] = {0,-1, 1, 0};
        /*
        /
        /             U (i-1,j) => (-1,0)
        /                   |
        /                   |
        /  L (i,j-1) -----(i,j)----- R (i,j+1) => (0,1)
        /    (0,-1)         |
        /                   |
        /             D (i+1,j) => (1,0)
        / 
        /  U = -1, 0
        /  R =  0, 1
        /  D =  1, 0
        /  L =  0,-1
        /
        / lexicographical order
        / D =  1  0 //s[0]
        / L =  0 -1 //s[1]
        / R =  0  1 //s[2]
        / U = -1  0 //s[3]
        /
        */
        
        bool isSafe(vector<vector<int>> mat, int n,int i, int j, vector<vector<int>> vis)
        {
            
            if( 
                i >= 0 && i <= n-1 && 
                j >= 0 && j <= n-1 && 
                vis[i][j] == 0 && 
                mat[i][j] == 1
            )
            {
                return true;
            }
            return false;
        }
       
        void solve(vector<vector<int>> mat, int n, int i, int j, vector<vector<int>> vis, string path, vector<string>&ans)
        {
            if(i == n-1 && j == n-1) { ans.push_back(path); return;}
            
            //mark visited
            vis[i][j] = 1;
            
            //x=0 -> 4 ==> try to all direction "D L R U"
            for(int x = 0; x<4; x++) {
                
                //checking condition
                if(isSafe(mat,n,i+di[x], j+dj[x], vis)) {
                    
                    //add 'D' or 'R' or 'U' or 'L' to current path
                    path += s[x];
                    
                    //x = 0 -> i + di[x], j + dj[x] -> "D"
                    //x = 1 -> i + di[x], j + dj[x] -> "L"
                    //x = 2 -> i + di[x], j + dj[x] -> "R"
                    //x = 3 -> i + di[x], j + dj[x] -> "U"
                    solve(mat, n, i+di[x], j+dj[x], vis, path, ans);
                    
                    //Restoreing current path
                    path.pop_back();
                }
            }
            
            //mark as unvisited
            vis[i][j] = 0;
       }  
  
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        
        //if first index if '0' we can't move to the next
        if(m[0][0] == 0) {return ans; } 
        
        string path = "";
        vector<vector<int>> visited (n,vector<int>(n,0));
        
        solve(m, n, 0, 0, visited, path, ans);
        
        return ans;
    }
};