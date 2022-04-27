class Solution {
public:
    int findParent(int node, vector<int> &parent){
      return parent[node]= node==parent[node] ? node : findParent(parent[node], parent);
    }
  
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        vector<int> parent(n);
        vector<bool> ans;
      
        // create n disjoint sets
        for(int i=0; i<n; ++i) parent[i]= i;
        
        // for every request check to ensure that we do not take union of any restricted pairs
        for(auto &req: requests){
          bool request_status= true;
          int req1= findParent(req[0], parent), req2= findParent(req[1], parent);
          for(auto &res: restrictions){
            int res1= findParent(res[0], parent), res2= findParent(res[1], parent);
            if((res1==req1 && res2==req2) || (res1==req2 && res2==req1)){
              request_status= false;
              break;
            }
          }
          
          if(request_status){
            ans.push_back(1);
            parent[req1]= req2;
          }else ans.push_back(0);
        }
      
      return ans;
    }
};