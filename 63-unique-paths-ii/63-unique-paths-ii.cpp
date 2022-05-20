class Solution {
public:
    int findUniquePaths(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp){
        // if the boundaries of the matrix are exceeded or an obstacle is reached
        if(i<0 || j<0 || i==mat.size() || j==mat[0].size() || mat[i][j]) return 0;
        // if the bottom-right corner is reached   
        if(i==mat.size()-1 && j==mat[0].size()-1) return 1;
      
        // if dp vector contains the ans
        if(dp[i][j]!=-1) return dp[i][j];
      
        // find total path count
        int path_count= 0;
        // move-right
        path_count+= findUniquePaths(i, j+1, mat, dp);
        // move-down
        path_count+= findUniquePaths(i+1, j, mat, dp);
        // return total path count
        return dp[i][j]= path_count;
    }
  
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n= obstacleGrid.size(), m= obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return findUniquePaths(0, 0, obstacleGrid, dp);
    }
};