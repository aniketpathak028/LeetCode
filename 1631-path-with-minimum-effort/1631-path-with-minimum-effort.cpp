typedef pair<int,pair<int,int>> pr;
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n= heights.size(), m= heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        vector<pair<int,int>> dir= {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        priority_queue<pr,vector<pr>,greater<pr>> pq;
        pq.push({0, {0,0}});
        dist[0][0]= 0;
        while(!pq.empty()){
          auto vert= pq.top();
          pq.pop();
          int i= vert.second.first, j= vert.second.second, node= heights[i][j];
          for(auto it: dir){
            if(i+it.first<0 || i+it.first>=n || j+it.second<0 || j+it.second>=m) continue;
            int new_node= heights[i+it.first][j+it.second];
            if(max(dist[i][j],abs(new_node-node)) < dist[i+it.first][j+it.second]){
              pq.push({max(dist[i][j],abs(new_node-node)),{i+it.first,j+it.second}});
              dist[i+it.first][j+it.second]= max(dist[i][j],abs(new_node-node));
            }
          }
        }
        return dist[n-1][m-1];
   }
};