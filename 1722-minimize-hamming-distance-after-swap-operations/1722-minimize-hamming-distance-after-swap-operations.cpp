class Solution {
public:
    int findParent(int node, vector<int> &parent){
      if(node==parent[node]) return node;
      return parent[node] = findParent(parent[node], parent);
    }
  
    void Union(int u, int v, vector<int> &parent){
      parent[findParent(u, parent)]= findParent(v, parent);   
    }
  
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
      int n= source.size();
      vector<int> parent(n);
      
      // create n disjoint sets
      for(int i=0; i<n; ++i) parent[i]= i;
      
      // take union of the pairs
      for(auto &pair: allowedSwaps)
        Union(pair[0], pair[1], parent);
      
      map<int,map<int,int>> mp; // map to store the set of numbers present in a union
      
      for(int i=0; i<n; ++i)
        mp[findParent(i, parent)][source[i]]++;
      
      
      int ans= 0;
      for(int i=0; i<n; ++i){
          if(mp[findParent(i, parent)][target[i]]) mp[findParent(i, parent)][target[i]]--;
          else ans++;
      }
          
      return ans;
    }
};