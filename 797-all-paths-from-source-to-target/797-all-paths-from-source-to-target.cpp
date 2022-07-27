class Solution {
public:
    void dfs(int src, int dest, vector<int> path, vector<vector<int>> &graph, vector<vector<int>> &ans){
      if(src==dest){
        path.push_back(dest);
        ans.push_back(path);
        return;
      }
      
      path.push_back(src);
      
      // try all the paths
      for(auto it: graph[src]){
        dfs(it, dest, path, graph, ans);
      }
    }
  
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(0, graph.size()-1, path, graph, ans);
        return ans;
    }
};