class Solution {
public:
bool repeat(vector<vector<char>>board,int x, int row,int col)
    {
       int cnt  = 0;
        for(int i = 0; i<9; i++)
        {
            int rx = board[row][i] - 48;
            int cx = board[i][col] - 48;
           if(cx==x){cnt++;}
           if(rx==x){cnt++;}
           
        }
         int startrow, endrow;
         if(row<=2&&row>=0) {startrow = 0;}
         if(row<=5&&row>=3) {startrow = 3;}
         if(row<=8&&row>=6) {startrow = 6;}
         endrow = startrow+3;
    
         int startcol, endcol;
         if(col<=2&&col>=0) {startcol = 0;}
         if(col<=5&&col>=3) {startcol = 3;}
         if(col<=8&&col>=6) {startcol = 6;}
         endcol = startcol + 3;     
         vector<int>arr;
         for(int r = startrow; r<endrow; r++)
         {
            for(int c = startcol; c<endcol; c++)
             {
               int xxx = board[r][c]-48;
               if(xxx>=0 && xxx<=9) { arr.push_back(xxx); }
             }            
         }
    
        for(int i = 0; i<arr.size();i++)
        { 
           for(int j = i+1;j<arr.size();j++)
           {
               if(arr[i] == arr[j]) cnt++;
           }
        }
        return cnt > 2;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        
        int s = 0;
        int e = row*col;
        
        for(int i = 0; i<row; i++)
        {
            for(int j =0; j<col; j++)
            {
                 int x = board[i][j] - 48;
                  if( 0<= x && x<=9){
                          if(repeat(board,x,i,j)) { return 0; }
                   }
             }
         }
        
        return 1;
    }
};