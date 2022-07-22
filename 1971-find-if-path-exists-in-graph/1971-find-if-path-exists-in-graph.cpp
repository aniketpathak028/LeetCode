class Solution {
public:
    bool dfs(int node, int dest, vector<int> &vis, vector<int> adj[]){
      if(node==dest) return true;
      if(!vis[node]){
        vis[node]= 1;
        for(auto &it: adj[node]){
          if(dfs(it, dest, vis, adj)) return true;
        }
      }
      return false;
    }
  
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // create adjacency list
        vector<int> adj[n];
        for(auto &edge: edges){
          adj[edge[0]].push_back(edge[1]);
          adj[edge[1]].push_back(edge[0]);
        }
        // run dfs to check the total number of valid paths
        vector<int> vis(n);
      
        return dfs(source, destination, vis, adj);
    }
};