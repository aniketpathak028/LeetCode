class Solution {
public:
    int findPathLength(int i, int j, int prev, vector<vector<int>> &mat, int dp[][201]){
        if(i<0 || j<0 || i==mat.size() || j==mat[0].size() || mat[i][j]<=prev) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int left= 1+findPathLength(i, j-1, mat[i][j], mat, dp);
        int right= 1+findPathLength(i, j+1, mat[i][j], mat, dp);
        int up= 1+findPathLength(i-1, j, mat[i][j], mat, dp);
        int down= 1+findPathLength(i+1, j, mat[i][j], mat, dp);
        return dp[i][j]= max(max(up, down),max(left, right));
     }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n= matrix.size(), m= matrix[0].size();
        int dp[201][201];
        int longest_path= 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                memset(dp, -1, sizeof(dp));
                longest_path= max(longest_path, findPathLength(i, j, -1, matrix, dp));
            }
        }
        return longest_path;
    }
};