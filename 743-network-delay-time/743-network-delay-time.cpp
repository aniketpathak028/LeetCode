class Solution {
public:
    int dijkstra(int src, vector<pair<int,int>> adj[], int V){
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; 
      vector<int> dist(V+1, INT_MAX);
      dist[src]= 0;
      pq.push({0, src});
      while(!pq.empty()){
        auto node= pq.top();
        pq.pop();
        for(auto &it: adj[node.second]){
          if(node.first+it.second<dist[it.first]){
            dist[it.first]= node.first+it.second;
            pq.push({node.first+it.second, it.first});
          }
        }
      }
      for(int i=1; i<=V ; ++i) if(dist[i]==INT_MAX) return -1;
      return *max_element(dist.begin()+1, dist.end());
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto &it: times){
          adj[it[0]].push_back({it[1],it[2]});
        }
        return dijkstra(k, adj, n);
    }
};