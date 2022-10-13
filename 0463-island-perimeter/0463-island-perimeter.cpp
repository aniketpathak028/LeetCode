class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &grid, int &count){
        if(i<0 || j<0 || i==grid.size() || j==grid[0].size()){
            count++;
            return;
        } 
        else if(i>=0 && j>=0 && i<grid.size() && j<grid[0].size()){
            if(grid[i][j]==2) return;
            else if(!grid[i][j]){
                 count++;
            return;
            }
        }
        grid[i][j]= 2;
        dfs(i+1, j, grid, count);
        dfs(i, j+1, grid, count);
        dfs(i-1, j, grid, count);
        dfs(i, j-1, grid, count);
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int n= grid.size(), m= grid[0].size();
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j]){
                    int count= 0;
                    dfs(i, j, grid, count);
                    return count;
                }
            }
        }
        return -1;
    }
};