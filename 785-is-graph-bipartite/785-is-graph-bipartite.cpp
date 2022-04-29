class Solution {
public:
    bool checkBipartite(int i, vector<vector<int>> &graph, vector<int> &col, int last){
      col[i]= last==0 ? 1 : 0;
      for(auto it: graph[i]){
        if(col[it]==-1){
          if(!checkBipartite(it, graph, col, col[i])) return false;
        }
        else if(col[it]==col[i]) return false;
      }
      return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int> col(n, -1);
        for(int i=0; i<n; ++i){
          if(col[i]==-1){
            if(!checkBipartite(i, graph, col, -1)) return false;
          }
        }
      return true;
    }
};