class Solution {
public:
    int mod= 1e9+7;
  
    int solve(int i, int j, int m, int n, int moves, vector<vector<vector<int>>> &dp){
      // if array out of bound add a move
      if(i<0 || j<0 || i==m || j==n) return 1;
      
      if(!moves) return 0; // if moves over return 0 moves
      
      if(dp[i][j][moves]!=-1) return dp[i][j][moves];
      
      long long up, down, left, right;
      
      up= solve(i-1, j, m, n, moves-1, dp);
      down= solve(i+1, j, m, n, moves-1, dp);
      right= solve(i, j+1, m, n, moves-1, dp);
      left= solve(i, j-1, m, n, moves-1, dp);
      
      return dp[i][j][moves]= (up+down+left+right)%mod;
    }
  
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove+1, -1)));
        return solve(startRow, startColumn, m, n, maxMove, dp);
    }
};