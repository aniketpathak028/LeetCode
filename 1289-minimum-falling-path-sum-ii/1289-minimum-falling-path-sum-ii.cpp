class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        // initialize DP
        vector<int> prev(n, 0);

        // base-case initialization
        for (int i = 0; i < n; i++)
        {
            prev[i] = grid[n - 1][i];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++)
            {
                int mini = INT_MAX;
               
                for (int dj = 0; dj < n; dj++)
                {
                    if (dj!=j)
                        mini = min(mini, prev[dj] + grid[i][j]);
                }

                curr[j] = mini;
            }
            prev = curr;
        }
        
        int mini = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            mini = min(mini, prev[i]);
        }

        return mini;
    }
};