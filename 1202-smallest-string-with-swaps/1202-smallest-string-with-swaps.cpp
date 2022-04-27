class Solution {
public:
    // finds the parent of the 
    int findParent(int node, vector<int> &parent){
      if(node==parent[node]) return node;
      return parent[node]= findParent(parent[node], parent);
    }
  
    void Union(int u, int v, vector<int> &parent){
      parent[findParent(u, parent)]= findParent(v, parent);
    }
  
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n= s.size();
        vector<int> parent(n);
        
        // create n disjoint sets
        for(int i=0; i<n; ++i) parent[i]= i;
        
        // take union of all pairs
        for(auto &pair: pairs)
          Union(pair[0], pair[1], parent);
        
        map<int,priority_queue<char,vector<char>,greater<char>>> chars; // map to store the characters in a min heap
        for(int i=0; i<n; ++i)
          chars[findParent(i, parent)].push(s[i]);
      
        for(int i=0; i<n; ++i){
          char c= chars[findParent(i, parent)].top();
          chars[findParent(i, parent)].pop();
          s[i]= c;
        }
        
        return s;
    }
};