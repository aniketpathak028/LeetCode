class Solution {
public:
    bool vis[3001][3001];
    void dfs(int i, int j, vector<vector<int>>& grid, int &area){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0 || vis[i][j]) return;
        vis[i][j]=1;
        area++;
        dfs(i+1,j,grid, area);
        dfs(i-1,j,grid, area);
        dfs(i,j+1, grid, area);
        dfs(i,j-1, grid, area);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        memset(vis, 0, sizeof(vis));
        for(int i=0; i<grid.size(); ++i)
            for(int j=0; j<grid[0].size(); ++j)
                if(!vis[i][j] && grid[i][j]==1){
                    int area= 0;
                    dfs(i, j, grid, area);
                    ans= max(ans, area);
                } 
        return ans;
    }
};