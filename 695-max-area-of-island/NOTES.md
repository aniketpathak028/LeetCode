**Simple DFS**
* Run dfs on all unvisitied 0's and calculate the area of every island.
* Store the max area and return
​
```
void dfs(int i, int j, int &area, vector<vector<bool>> &vis, vector<vector<int>> &grid){
if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || vis[i][j] || grid[i][j]==0) return;
vis[i][j]= 1;
area++;
dfs(i+1, j, area, vis, grid);
dfs(i-1, j, area, vis, grid);
dfs(i, j+1, area, vis, grid);
dfs(i, j-1, area, vis, grid);
}
int maxAreaOfIsland(vector<vector<int>>& grid) {
int max_area= 0;
int n, m;
n= grid.size();
m= grid[0].size();
vector<vector<bool>> vis(n, vector<bool>(m, 0));
for(int i=0; i<grid.size(); ++i){
for(int j=0; j<grid[0].size(); ++j){
if(!vis[i][j] && grid[i][j]==1){
int area = 0;
dfs(i, j, area, vis, grid);
max_area = max(max_area, area);
}
}
}
return max_area;
}
```