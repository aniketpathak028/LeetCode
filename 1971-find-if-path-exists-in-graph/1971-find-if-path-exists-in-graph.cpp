class Solution {
public:
    bool dfs(int i, int d, vector<int> &vis, vector<int> adj[]){
        if(i==d) return true;
        vis[i]= 1;
        
        for(auto it: adj[i]){
            if(!vis[it]){
                if(dfs(it, d, vis, adj)) return true;
            }
        }
        
        return false;
        
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        vector<int> vis(n, 0);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return dfs(source, destination, vis, adj);
    }
};