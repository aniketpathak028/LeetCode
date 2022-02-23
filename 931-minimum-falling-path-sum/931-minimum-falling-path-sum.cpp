class Solution {
public:
    int solve(int i, int j, int n, vector<vector<int>>& matrix, vector<vector<int>> &dp){
        // out-of-bound condition
        if(j<0 || j>=n) return 1e8;
        
        //base case
        if(i==n-1) return matrix[i][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int mini = INT_MAX;
        for(int dj=-1; dj<=1; dj++){
            mini = min(mini, solve(i+1, j+dj, n, matrix, dp)+matrix[i][j]);
        }
        
        return dp[i][j] = mini;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int mini= INT_MAX;
        int n= matrix.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        for(int i=0; i<n; i++){
            mini = min(mini, solve(0, i, n, matrix, dp));
        }
        
        return mini;
    }
};