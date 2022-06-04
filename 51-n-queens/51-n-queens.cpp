class Solution {
public:
    bool isSafe(int i, int j, vector<string> &board, map<int,int> m1, map<int,int> m2){
      // check column above
      for(int i1= i; i1>=0; --i1) if(board[i1][j]=='Q') return false;
      // check for diagonals
      if(m1[i-j] || m2[i+j]) return false;
      return true;
    }
  
    void findAllSolutions(int i, vector<string> &board, vector<vector<string>> &ans, map<int,int> &m1, map<int,int> &m2, int n){
      // if the board is exceeded, a solution must have been found
      if(i==n){
        ans.push_back(board);
        return;
      }
      
      // iterate for all columns and check if a Queen can be placed
      for(int j=0; j<n; ++j){
        if(isSafe(i, j, board, m1, m2)){
          // if it is safe to place a Queen, place a queen and then backtrack
          board[i][j]= 'Q';
          m1[i-j]= 1;
          m2[i+j]= 1;
          findAllSolutions(i+1, board, ans, m1, m2, n);
          m1[i-j]= 0;
          m2[i+j]= 0;
          board[i][j]= '.';
        }
      }
    }
  
    vector<vector<string>> solveNQueens(int n) {
      // ans vector to store all board possiblities
      vector<vector<string>> ans;
    
      // represents a row of the board
      string row(n, '.');
      
      // nxn chess board
      vector<string> board(n, row);
      
      // maps to keep track of attacked positions
      map<int,int> m1, m2;
      
      // function to find all board possiblities
      findAllSolutions(0, board, ans, m1, m2, n);
      
      return ans;
    }
};