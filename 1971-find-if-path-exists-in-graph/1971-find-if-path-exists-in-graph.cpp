class Solution {
public:
    void bfs(int node, vector<int> adj[], vector<int> &vis){
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int curr= q.front();
            q.pop();
            vis[curr]= 1;
            for(auto &it: adj[curr]){
                if(!vis[it]){
                    q.push(it);
                }
            }
        }
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // create adjacency-matrix
        vector<int> adj[n];
        for(auto &e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        // create visited array
        vector<int> vis(n);
        // call bfs for source-node
        bfs(source, adj, vis);
        return vis[destination];
    }
};