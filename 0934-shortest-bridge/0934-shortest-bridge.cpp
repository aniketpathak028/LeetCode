class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &grid, queue<pair<int,int>> &q){
        if(i<0 || j<0 || i==grid.size() || j==grid[0].size() || !grid[i][j] || grid[i][j]==2) return;
        grid[i][j]= 2; // mark as visited
        q.push({i,j});
        dfs(i+1, j, grid, q);
        dfs(i-1, j, grid, q);
        dfs(i, j+1, grid, q);
        dfs(i, j-1, grid, q);
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n= grid.size(), m= grid[0].size();
        queue<pair<int,int>> q;
        // push all cells in an island into queue
        bool flag= true;
        for(int i=0; i<n; ++i){
            if(!flag) break;
            for(int j=0; j<m; ++j){
                if(grid[i][j]){
                    dfs(i, j, grid, q);
                    flag= false;
                    break;
                }
            }
        }
        // find the shortest path
        vector<vector<int>> dir= {{-1,0}, {1,0}, {0,-1}, {0,1}};
        int steps= 0;
        while(!q.empty()){
            int size= q.size();
            while(size--){
                int i= q.front().first, j= q.front().second;
                q.pop();
                for(auto &it: dir){
                    if(i+it[0]>=0 && j+it[1]>=0 && i+it[0]<n && j+it[1]<m && grid[i+it[0]][j+it[1]]==1) return steps;
                    else if(i+it[0]>=0 && j+it[1]>=0 && i+it[0]<n && j+it[1]<m && !grid[i+it[0]][j+it[1]]){
                        q.push({i+it[0], j+it[1]});
                        grid[i+it[0]][j+it[1]]= 2;
                    }
                }
            }
            steps++;
        }
        
        return steps;
    }
};