class Solution {
public:
    bool isSafePlace(int row, int col, vector<string> board, int n){
        int row_copy = row;
        int col_copy = col;
        
        // left diagonal upper
        while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }
        
        row = row_copy;
        col = col_copy;
        
        // left row
        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }
        
        row = row_copy;
        col = col_copy;
        
        // right diagonal upper
        while(row<=n-1 && col>=0){
            if(board[row][col]=='Q') return false;
            col--;
            row++;
        }
        
        return true;
    }
    void solution(int col, vector<string> &board, vector<vector<string>> &ans, int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        
        for(int row=0; row<n; row++){
            if(isSafePlace(row, col, board, n)){
                board[row][col]= 'Q';
                solution(col+1, board, ans, n);
                board[row][col]= '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string row(n, '.');
        vector<string> board(n, row);
        solution(0, board, ans, n);
        return ans;
    }
};