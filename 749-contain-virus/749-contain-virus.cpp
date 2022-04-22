class Cluster {
  public:
    set<pair<int,int>> c; // set of contaminated cells in a cluster
    set<pair<int,int>> uc; // set of uncontaminated cells around the cluster
    int wall_count= 0; // wall count to quarantine the cluster
};

// overloading < operator, for priority queue
bool operator<(const Cluster &c1, const Cluster &c2){
  return c1.uc.size()<c2.uc.size();
}

class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &vis, Cluster &c){
      // out of bound cases, visited cells, and the cells that have been already quarantined
      if(i<0 || j<0 || i==grid.size() || j==grid[0].size() || vis[i][j] || grid[i][j]==-1) return;
      
      if(grid[i][j]==0){
        // this is an uncontaminated cell
        c.uc.insert({i,j}); // insert into the set of uc
        c.wall_count++; // increase the wall count
        
        return;
      }
      
      // mark the current cell as visited 
      vis[i][j]= 1;
      
      // this is a contaminated cell
      c.c.insert({i,j});
      
      // run dfs for all neighbouring cells
      dfs(i+1, j, grid, vis, c);
      dfs(i, j+1, grid, vis, c);
      dfs(i-1, j, grid, vis, c);
      dfs(i, j-1, grid, vis, c);
    }
      
    int containVirus(vector<vector<int>>& isInfected) {
        int n= isInfected.size(), m= isInfected[0].size();
        int total_wall= 0;
        while(true){
          vector<vector<int>> vis(n, vector<int>(m, 0));
          priority_queue<Cluster> pq; // maintain a pq to find the most infecting cluster
          
          // traverse the grid and create the clusters
          for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
              if(!vis[i][j] && isInfected[i][j]==1){
                Cluster c;
                dfs(i, j, isInfected, vis, c);
                pq.push(c); // push the cluster to the priority queue
              }
            }
          }
          
          if(pq.empty()) break; // if pq is empty there are no contaminated regions
          
          Cluster c= pq.top(); // find the most infecting cluster
          pq.pop();
          
          total_wall += c.wall_count; // add the wall count of the cluster to the total count
          
          // make wall around the current cluster
          for(auto &cell: c.c){
            // mark the cell as -1 so that it is no longer considered next time
            isInfected[cell.first][cell.second]= -1; 
          }
          
          // infect the neighbouring uncontaminated cells of all the remaining clusters
          while(!pq.empty()){
            c= pq.top();
            pq.pop();
            for(auto &cell: c.uc){
              isInfected[cell.first][cell.second]= 1;
            }
          }
        }
      return total_wall;
    }
};