class Solution {
public:
    void dfs(int i, int j, int prev, vector<vector<int>> &vis, vector<vector<int>> &heights){
        // base case
        if(i<0 || j<0 || i==heights.size() || j==heights[0].size() || vis[i][j] || heights[i][j]<prev) return;
        
        // mark as visited
        vis[i][j]= 1;
        
        // run dfs for all adjacent nodes
        dfs(i, j+1, heights[i][j], vis, heights);
        dfs(i, j-1, heights[i][j], vis, heights);
        dfs(i+1, j, heights[i][j], vis, heights);
        dfs(i-1, j, heights[i][j], vis, heights);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n= heights.size(), m= heights[0].size();
        
        // create two matrix to store regions for atlantic and pacific
        vector<vector<int>> atl(n, vector<int>(m, 0)), pac(n, vector<int>(m, 0));
        
        // run dfs for pacific
        for(int j=0; j<m; ++j) dfs(0, j, -1, atl, heights);
        for(int i=0; i<n; ++i) dfs(i, 0, -1, atl, heights);
        
        // run dfs for atlantic
        for(int i=0; i<n; ++i) dfs(i, m-1, -1, pac, heights);
        for(int j=0; j<m; ++j) dfs(n-1, j, -1, pac, heights);
        
        vector<vector<int>> ans;
        
        // take the intersection of the two matrices ie. atlantic and pacific
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(atl[i][j] && pac[i][j]){
                    vector<int> cell= {i, j};
                    ans.push_back(cell);
                }
            }
        }
        
        return ans;
    }
};