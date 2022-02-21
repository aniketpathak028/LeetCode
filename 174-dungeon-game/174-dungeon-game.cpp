class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& dungeon, int r, int c,vector<vector<int>> &dp){
        // out-of-bound condition
        if(i>=r || j>=c) return 1e8;
        
        // base-case
        if(i==r-1 && j==c-1) return dungeon[r-1][c-1]<0 ?  -dungeon[r-1][c-1]+1 :  1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int rgt=solve(i, j+1, dungeon, r, c, dp);
        int dwn=solve(i+1, j, dungeon, r, c, dp);
        
        int mini = min(rgt, dwn)-dungeon[i][j];
        
        
        return dp[i][j]= mini<=0 ? 1 : mini;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int r = dungeon.size();
        int c = dungeon[0].size();
        vector<vector<int>> dp(r, vector<int>(c, -1));
        return solve(0, 0, dungeon, r, c,dp);
    }
};