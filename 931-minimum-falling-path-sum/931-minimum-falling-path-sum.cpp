class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
    int mini = INT_MAX;
    int n = matrix.size();

    // initialize DP
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // base-case initialization
    for (int i = 0; i < n; i++) dp[n-1][i]= matrix[n-1][i];
    

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < n; j++){
            int mini = INT_MAX;
            for (int dj = -1; dj <= 1; dj++)
            {
                if(j+dj>=0 && j+dj<n) mini = min(mini, dp[i + 1][j + dj] + matrix[i][j]);
            }

            dp[i][j] = mini;
        }
    }


    for (int i = 0; i < n; i++) mini = min(mini, dp[0][i]);
    

    return mini;
    }
};