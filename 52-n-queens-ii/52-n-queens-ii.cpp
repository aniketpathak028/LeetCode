class Solution {
public:
    bool isSafe(int row, int col, vector<string> &board, map<int,int> &m1, map<int,int> &m2){
        // check vertical
        for(int i=row; i>=0; i--) if(board[i][col]=='Q') return false;
        
        // check diagonals
        if(m1[row-col] || m2[row+col]) return false;
      
        // if the position is not attacked by any Queens it is safe
        return true;
    }
  
    int numberOfSolutions(int row, vector<string> &board, map<int,int> &m1, map<int,int> &m2, int n){
      // if the board is exceeded, a solution is found
      if(row==n) return 1;
      
      // iterate for all columns in a row, to count all possiblities
      int tot_count= 0;
      
      for(int col=0; col<n; ++col){
        if(isSafe(row, col, board, m1, m2)){
          board[row][col]= 'Q';
          m1[row-col]= 1;
          m2[row+col]= 1;
          tot_count+= numberOfSolutions(row+1, board, m1, m2, n);
          m2[row+col]= 0;
          m1[row-col]= 0;
          board[row][col]= '.';
        }
      }
      
      // return total count of solutions
      return tot_count;
    }
  
    int totalNQueens(int n) {
        // row of the chess board
        string row(n, '.');
        // n x n chess board
        vector<string> board(n, row);
        // maps to keep track of attacked positions
        map<int,int> m1, m2;
        // return the count of distinct solutions
        return numberOfSolutions(0, board, m1, m2, n);
    }
};