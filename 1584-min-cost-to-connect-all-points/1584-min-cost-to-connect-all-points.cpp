class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n= points.size();
        vector<int> key(n, INT_MAX), parent(n, -1), MST(n, 0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0, 0});
        key[0]= 0;
        while(!pq.empty()){
          auto node= pq.top().second;
          pq.pop();
          int i= points[node][0], j= points[node][1];
          MST[node]= 1;
          for(int it=0; it<n; ++it){
            if(it!=node){
              if(!MST[it] && abs(points[it][0]-i)+abs(points[it][1]-j)<key[it]){
                key[it]= abs(points[it][0]-i)+abs(points[it][1]-j);
                parent[it]= node;
                pq.push({key[it], it});
              }
            }
          }
        }
      return accumulate(key.begin(), key.end(), 0);
    } 
};