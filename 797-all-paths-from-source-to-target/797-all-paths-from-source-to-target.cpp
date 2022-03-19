class Solution {
public:
    void dfs(int i, int n, vector<int> adj[], vector<int> path, vector<vector<int>> &ans){
        if(i==n-1){
            path.push_back(n-1);
            ans.push_back(path);
            return;
        }
        path.push_back(i);
        for(auto it: adj[i]){
            dfs(it, n, adj, path, ans);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        int n= graph.size(); // number of nodes
        vector<int> adj[n];
        // creating the adjacency list
        for(int i=0; i<n; i++) {
            for(auto it: graph[i]){
                adj[i].push_back(it);
            }
        }
        vector<int> path;
        dfs(0, n, adj, path, ans);
        return ans;
    }
};