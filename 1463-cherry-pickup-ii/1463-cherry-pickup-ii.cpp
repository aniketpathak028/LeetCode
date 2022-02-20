class Solution {
public:
    int maxCherry(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp){
        // base-case (out-of-bound condition)
        if(j1<0 || j2<0 || j1>grid[0].size()-1 || j2>grid[0].size()-1)
            return -1e8;
        
        // base-case (reached the last row)
        if(i==grid.size()-1) {
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        } 
        
        // check if the value already exists
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        
        // trying all combinations and returning the maximum
        int maxi = 0;
        for(int dj1=-1; dj1<=1; dj1++){
            for(int dj2=-1; dj2<=1; dj2++){
                int value = maxCherry(i+1, j1+dj1, j2+dj2, grid, dp);
                if(j1==j2) value += grid[i][j1];
                else value += grid[i][j1]+grid[i][j2];
                maxi = max(maxi, value);
            }
        }
                             
        return dp[i][j1][j2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int row_length = grid[0].size()-1;
        int cols = grid.size();
        vector<vector<vector<int>>> dp(cols, vector<vector<int>>(row_length+1, vector<int>(row_length+1, -1)));
        return maxCherry(0, 0, row_length, grid, dp);
    }
};