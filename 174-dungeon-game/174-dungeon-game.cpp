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
        int x = dungeon.size();
        int y = dungeon[0].size();
        vector<vector<int>> dp(x, vector<int>(y, -1));
        // return solve(0, 0, dungeon, r, c,dp);
        
        // vector<vector<int>> dp(x, vector<int>(y, 0));

    for (int i = x - 1; i >= 0; i--)
    {
        for (int j = y-1; j >= 0; j--)
        {
            if (i == x - 1 && j == y - 1)
            {
                // base-case-intialization
                dp[x - 1][y - 1] = dungeon[x - 1][y - 1] > 0 ? 1 : -dungeon[x - 1][y - 1] + 1;
            }
            else
            {
                int rgt = 1e8;
                int dwn = 1e8;
                if (j < y - 1)
                    rgt = dp[i][j + 1];
                if (i < x - 1)
                    dwn = dp[i + 1][j];

                int mini = min(rgt, dwn) - dungeon[i][j];

                if (mini <= 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = mini;
            }
        }
    }

    return dp[0][0];
    }
};