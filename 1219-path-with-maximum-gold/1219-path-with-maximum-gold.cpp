class Solution {
public:
    vector<vector<int>> dir= {{0,1}, {1,0}, {-1,0}, {0,-1}};
    int findGold(int i, int j, vector<vector<int>> &grid){
      if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || !grid[i][j]) return 0;
      int start_val= grid[i][j], maxi= start_val;
      grid[i][j]= 0;
      for(auto &it: dir){
        maxi= max(maxi, start_val+findGold(i+it[0], j+it[1], grid));
      }
      grid[i][j]= start_val;
      return maxi;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n= grid.size(), m= grid[0].size(), ans= 0; 
        for(int i=0; i<n; ++i)
          for(int j=0; j<m; ++j)
            if(grid[i][j]>0) ans= max(ans, findGold(i, j, grid));
        return ans;
    }
};