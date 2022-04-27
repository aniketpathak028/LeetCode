class Solution {
public:
    int findParent(int node, vector<int> &person){
      if(node==person[node]) return node;
      return person[node]= findParent(person[node], person);
    }
  
    void Union(int u, int v, vector<int> &person){
      person[findParent(u, person)]= findParent(v, person);
    }
  
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        vector<int> person(n);
        // create n disjoint sets
        for(int i=0; i<n; ++i) person[i]= i;
        vector<bool> ans; // answer vector
        
        for(auto &req: requests){
          bool state= true;
          int req1= findParent(req[0], person), req2= findParent(req[1], person);
          for(auto &res: restrictions){
            if((findParent(res[0], person)==req1 && findParent(res[1], person)==req2) || (findParent(res[1], person)==req1 && findParent(res[0], person)==req2)){
              state= false;
              break;
            }
          }
          if(state){
            person[req1]= req2;
            ans.push_back(1);
          }
          else{
            ans.push_back(0);
          }
        }
      return ans;
    }
};