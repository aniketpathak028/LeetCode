class Solution {
public:
    bool vis[3001][3001];
    void dfs(int i, int j, vector<vector<char>>& grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='0' || vis[i][j]) return;
        vis[i][j]=1;
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1, grid);
        dfs(i,j-1, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        memset(vis, 0, sizeof(vis));
        int c=0;
        for(int i=0; i<grid.size(); ++i)
            for(int j=0; j<grid[0].size(); ++j)
                if(!vis[i][j] && grid[i][j]=='1') { c++; dfs(i, j, grid);}
        return c;
    }
};