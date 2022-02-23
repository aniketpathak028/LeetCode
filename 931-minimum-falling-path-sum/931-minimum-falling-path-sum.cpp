class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int mini = INT_MAX;
        int n = matrix.size();

        // initialize DP
        vector<int> prev(n, 0);

        // base-case initialization
        for (int i = 0; i < n; i++)
        {
            prev[i] = matrix[n - 1][i];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++)
            {
                int mini = INT_MAX;
                for (int dj = -1; dj <= 1; dj++)
                {
                   if(j+dj<n && j+dj>=0) mini = min(mini, prev[j + dj] + matrix[i][j]);
                }

                curr[j] = mini;
            }
            prev= curr;
        }

        for (int i = 0; i < n; i++)
        {
            mini = min(mini, prev[i]);
        }

        return mini;
    }
    
};