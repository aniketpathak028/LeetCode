#include<bits/stdc++.h>
class Solution {
public:
   int solve(int i1, int j1, int i2, int j2, int n, vector<vector<int>> &grid, vector<vector<vector<vector<int>>>> &dp)
{
    // out-of-bound condition
    if (i1 >= n || i2 >= n || j1 >= n || j2 >= n || grid[i1][j1] == -1 || grid[i2][j2] == -1)
        return -1e8;

    // base condition
    if (i1 == n - 1 && j1 == n - 1 && i2 == n - 1 && j2 == n - 1)
        return grid[n - 1][n - 1];

    if (dp[i1][j1][i2][j2] != -1)
        return dp[i1][j1][i2][j2];

    int value = grid[i1][j1];
    if (i1 != i2)
        value += grid[i2][j2];

    int temp= max({solve(i1 + 1, j1, i2 + 1, j2, n, grid, dp), solve(i1 + 1, j1, i2, j2 + 1, n, grid, dp) , solve(i1, j1 + 1, i2 + 1, j2, n, grid, dp), solve(i1, j1 + 1, i2, j2 + 1, n, grid, dp)});
    value += temp;
    return dp[i1][j1][i2][j2] = value;
}
int cherryPickup(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, -1))));

    return max(0,solve(0, 0, 0, 0, n, grid, dp));
}

};