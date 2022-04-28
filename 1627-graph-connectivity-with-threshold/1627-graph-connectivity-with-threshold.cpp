class Solution {
public:
    int findParent(int city, vector<int> &cities){
      if(city==cities[city]) return city;
      return cities[city]= findParent(cities[city], cities);
    }
  
    void Union(int u, int v, vector<int> &cities){
      cities[findParent(u, cities)]= findParent(v, cities);
    }
  
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        vector<bool> ans;
        
        // create n disjoint sets
        vector<int> cities(n+1);
        for(int i=1; i<n+1; ++i) cities[i]= i;
        
        // seive of eratosthenes to take union of all cities with gcd > threshold 
        for(int i=threshold+1; i<=n; ++i)
          for(int j=i*2; j<=n; j+=i)
            Union(i, j, cities);
        
        
        for(auto &q: queries){
          if(findParent(q[0], cities)==findParent(q[1], cities)) ans.push_back(1);
          else ans.push_back(0);
        }
      
      return ans;
    }
};