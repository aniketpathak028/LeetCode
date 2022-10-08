class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size(), m= grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m));
        int fresh= 0;
        int time= 0;
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> dir= {{-1,0}, {1,0}, {0,-1}, {0,1}};
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j]==1) fresh++;
                if(grid[i][j]==2) q.push({{i,j},0});
            }
        }
        while(!q.empty()){
            int i= q.front().first.first, j= q.front().first.second, t= q.front().second;
            q.pop();
            time= max(time, t);
            for(auto &it: dir){
                if(i+it[0]>=0 && i+it[0]<n && j+it[1]>=0 && j+it[1]<m && vis[i+it[0]][j+it[1]]!=2 && grid[i+it[0]][j+it[1]]==1){
                    q.push({{i+it[0], j+it[1]}, t+1});
                    fresh--;
                    vis[i+it[0]][j+it[1]]= 2;
                }
            }
        }
        if(fresh) return -1;
        return time;
    }
};