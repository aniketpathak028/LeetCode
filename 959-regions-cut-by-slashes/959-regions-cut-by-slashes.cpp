class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &vis){
      if(i<0 || j<0 || i==mat.size() || j==mat[0].size() || mat[i][j] || vis[i][j]) return;
      
      vis[i][j]= 1;
      
      dfs(i+1, j, mat, vis);
      dfs(i-1, j, mat, vis);
      dfs(i, j+1, mat, vis);
      dfs(i, j-1, mat, vis);
    }  
  
    int regionsBySlashes(vector<string>& grid) {
      
        int n= grid.size();
        vector<vector<int>> mat(3*n, vector<int>(3*n, 0)); // representing each cell as a 3X3 matrix
        
        for(int i=0; i<n; ++i){
          for(int j=0; j<n; ++j){
            // origin for the 3X3 matrix
            int i1= 3 * i, j1= 3 * j;
            
            // mark the cell as '/'
            if(grid[i][j]=='/'){ 
              mat[i1][j1+2]= 1;
              mat[i1+1][j1+1]= 1;
              mat[i1+2][j1]= 1;
            }
            
            // mark the cell as '/'
            else if(grid[i][j]=='\\'){
              mat[i1][j1]= 1;
              mat[i1+1][j1+1]= 1;
              mat[i1+2][j1+2]= 1;
            }
          }
        }
      
        vector<vector<int>> vis(3*n, vector<int>(3*n, 0)); // visited matrix for dfs
      
        int count_regions= 0; // count number of islands
        
        // run dfs for the matrix
        for(int i=0; i<3*n; ++i){
          for(int j=0; j<3*n; ++j){
            if(!mat[i][j] && !vis[i][j]){
              dfs(i, j, mat, vis);
              count_regions++;
            }
          }
        }
      
        return count_regions;
    }
};