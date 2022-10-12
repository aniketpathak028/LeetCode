class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]) return -1;
        int n= grid.size(), m= grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        vector<vector<int>> dir= {{0,-1}, {0,1}, {1,0}, {-1,0}, {-1,-1}, {1,1}, {-1,1}, {1,-1}};
        queue<pair<int,int>> q;
        q.push({0,0});
        dist[0][0]= 1;
        while(!q.empty()){
            auto node= q.front();
            q.pop();
            int i= node.first, j= node.second;
            for(auto &it: dir){
                if(i+it[0]>=0 && j+it[1]>=0 && i+it[0]<n && j+it[1]<m && !grid[i+it[0]][j+it[1]] && dist[i][j]+1<dist[i+it[0]][j+it[1]]){
                    q.push({i+it[0], j+it[1]});
                    dist[i+it[0]][j+it[1]]= dist[i][j]+1;
                }
            }
        }
        if(dist[n-1][m-1]==INT_MAX) return -1;
        return dist[n-1][m-1];
    }
};