class Solution {
public:
 
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n);
        for (int i = 0; i < n; i++)
        {
            vector<int> row(i + 1, -1);
            dp[i] = row;
        }
        for (int i = 0; i < n; i++){
            dp[n - 1][i] = triangle[n - 1][i];
        }
        for (int i = n-2; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
            {
                int d, dr;
                d = triangle[i][j] + dp[i+1][j];
                dr = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(d, dr);
            }
        }

        return dp[0][0];
    }
};