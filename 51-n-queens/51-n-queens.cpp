class Solution {
public:
  
    bool isSafe(int i, int j, vector<string> &board, map<int,int> &mp_top_down, map<int,int> &mp_bottom_up){
      // check vertical 
      for(int i1=i; i1>=0; i1--)
        if(board[i1][j]=='Q') return false;
      // check diagonals
      if(mp_top_down[i-j]==1 || mp_bottom_up[i+j]==1) return false;
      return true;
    }
    
    void findAllSolutions(int i, vector<string> &board, vector<vector<string>> &ans, int n, map<int,int> &mp_top_down, map<int,int> &mp_bottom_up){
      // base-case, board exceeded hence a solution must have been found
      if(i==n){
        // insert the board into ans
        ans.push_back(board);
        return;
      }
      
      // for a given row, check all the columns if it is valid to insert a queen
      for(int j=0; j<n; ++j){
        if(isSafe(i, j, board, mp_top_down, mp_bottom_up)){
          board[i][j]= 'Q';
          mp_top_down[i-j]= 1;
          mp_bottom_up[j+i]= 1;
          findAllSolutions(i+1, board, ans, n, mp_top_down, mp_bottom_up);
          mp_top_down[i-j]= 0;
          mp_bottom_up[j+i]= 0;
          board[i][j]= '.';
        }
      }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        // ans vector containing all the board possiblities for n
        vector<vector<string>> ans;
        // represents a row of the board
        string row(n, '.');
        // represents the chess board containing n rows
        vector<string> board(n, row);
        // maps to keep track of queens 
        map<int,int> mp_top_down, mp_bottom_up;
        findAllSolutions(0, board, ans, n, mp_top_down, mp_bottom_up);
      
        return ans;
    }
};