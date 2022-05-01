// Union Find class
class UnionFind{
  vector<int> parent;
  int size;
  
  public:
  
  UnionFind(int n) : parent(n), size(n) {
    for(int i=0; i<n; ++i) parent[i]= i;
  }
  
  int find(int node){
    if(node==parent[node]) return node;
    return parent[node]= find(parent[node]);
  }
  
  void Union(int u, int v){
    if(find(u)==find(v)) return;
    parent[find(u)]= find(v);
    size--;
  }
  
  bool connected(int u, int v){
    return find(u)==find(v);
  }
  
  int getSize() {return size;}
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        // create two Union Find for alice and bob
        UnionFind a(n+1), b(n+1);
      
        int ans= 0; // ans i.e. the max number of edges that can be removed
        
        // first we connect all type 3 edges
        for(auto &edge: edges){
          if(edge[0]==3){
            if(a.connected(edge[1], edge[2])) ans++; // if already connected skip and increment ans
            else{
              // else connect the nodes in both a and b
              a.Union(edge[1], edge[2]);
              b.Union(edge[1], edge[2]);
            }
          }
        }
      
        // now we check for type 1 and 2 edges
        for(auto &edge: edges){
          if(edge[0]==1){
            if(a.connected(edge[1], edge[2])) ans++;
            else a.Union(edge[1], edge[2]);
          }else if(edge[0]==2){
            if(b.connected(edge[1], edge[2])) ans++;
            else b.Union(edge[1], edge[2]);
          }
        }
      
      if(a.getSize()==2 && b.getSize()==2) return ans;
      return -1;
    }
};