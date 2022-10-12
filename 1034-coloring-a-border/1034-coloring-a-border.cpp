class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n= grid.size(), m= grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m));
        vector<vector<int>> dir= {{-1,0}, {1,0}, {0,1}, {0,-1}};
        queue<pair<int,int>> q;
        q.push({row,col});
        vis[row][col]= 1;
        while(!q.empty()){
            auto node= q.front();
            q.pop();
            int i= node.first, j= node.second;
            int c= grid[i][j];
            for(auto &it: dir){
                if(i+it[0]>=0 && i+it[0]<n && j+it[1]>=0 && j+it[1]<m){
                    if(grid[i+it[0]][j+it[1]]==c && !vis[i+it[0]][j+it[1]]){
                       q.push({i+it[0], j+it[1]});
                       vis[i+it[0]][j+it[1]]= 1; 
                    }
                    else if(grid[i+it[0]][j+it[1]]!=c && !vis[i+it[0]][j+it[1]]){
                        grid[i][j]= color;
                    }
                }else grid[i][j]= color;
            }
        }
        return grid;
    }
};