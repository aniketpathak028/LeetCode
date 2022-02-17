class Solution {
public:
    int solve(vector<vector<int>> &triangle, int i, int j, int n, vector<vector<int>> &dp)
    {
        if (i == n-1)
            return triangle[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        int d, dr;
        d = triangle[i][j] + solve(triangle, i + 1, j, n, dp);
        dr = triangle[i][j] + solve(triangle, i + 1, j + 1, n, dp);

        return dp[i][j] = min(d, dr);
    }


    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
                 vector<vector<int>> dp(n);
            for (int i = 0; i < n; i++)
            {
                vector<int> row(i + 1, -1);
                dp[i] = row;
            }
            return solve(triangle, 0, 0, n, dp);
    }
};