class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
      if(grid[0][0]!=0) return -1; 
      int n= grid.size();
      vector<vector<int>> dir= {{1,0}, {0,1}, {-1,0}, {0,-1}, {1,1}, {-1,-1}, {1,-1}, {-1,1}}; 
      vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
      queue<pair<int,int>> q;
      q.push({0,0});
      dist[0][0]= 0;
      while(!q.empty()){
        int i= q.front().first, j= q.front().second;
        q.pop();
        int nd= dist[i][j]+1;
        for(auto it: dir){
          int ni= i+it[0], nj= j+it[1];
          if(ni>=0 && nj>=0 && ni<n && nj<n && nd<dist[ni][nj] && grid[ni][nj]!=1){
            q.push({ni,nj});
            dist[ni][nj]= nd;
          }
        }
      }
      return dist[n-1][n-1] == INT_MAX ? -1 : dist[n-1][n-1]+1;
    }
};