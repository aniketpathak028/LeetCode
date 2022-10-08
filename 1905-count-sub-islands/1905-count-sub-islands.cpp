class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &grid1, vector<vector<int>> &grid2, bool &ans){
        if(i<0 || j<0 || i==grid2.size() || j==grid2[0].size()|| !grid2[i][j]) return;
            ans= ans && grid1[i][j];
            grid2[i][j]= 0;
            dfs(i+1, j, grid1, grid2, ans);
            dfs(i-1, j, grid1, grid2, ans);
            dfs(i, j+1, grid1, grid2, ans);
            dfs(i, j-1, grid1, grid2, ans);
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n= grid1.size(), m= grid1[0].size();
        int cnt= 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid2[i][j]){
                    bool ans= true;
                    dfs(i, j, grid1, grid2, ans);
                    if(ans) cnt++;
                }
            }
        }
        return cnt;
    }
};