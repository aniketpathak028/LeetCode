class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &vis, int &area){
      if(i<0 || j<0 || i==grid.size() || j==grid[0].size() || vis[i][j] || !grid[i][j]) return;
      
      vis[i][j]= 1;
      area++;
      
      dfs(i+1, j, grid, vis, area);
      dfs(i-1, j, grid, vis, area);
      dfs(i, j+1, grid, vis, area);
      dfs(i, j-1, grid, vis, area);      
    }
  
    int maxAreaOfIsland(vector<vector<int>>& grid) {
      int maxi= 0;
      int n= grid.size(), m= grid[0].size();
      vector<vector<int>> vis(n, vector<int>(m));
      for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
          if(grid[i][j] && !vis[i][j]){
            int area= 0;
            dfs(i, j, grid, vis, area);
            maxi= max(maxi, area);
          }
        }
      }
      return maxi;
    }
};