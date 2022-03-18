class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n= edges.size();
        int V= n+1;
        vector<int> adj[V+1];
        for(int i=0; i<n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int center;
        for(int i=1; i<=V; i++){
            if(adj[i].size()==n) center=i;
        }
        return center;
    }
};