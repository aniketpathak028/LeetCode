class Solution {
public:
    bool isSimilar(string s1, string s2){
      vector<int> idx;
      for(int i=0; i<s1.size(); ++i) if(s1[i]!=s2[i]) idx.push_back(i);
      if(idx.size()<2 || idx.size()>2) return false;
      swap(s1[idx[0]], s1[idx[1]]);
      return s1==s2 ? 1 : 0;
    }
  
    string findParent(string &str, unordered_map<string,string> &parent){
      if(parent[str]==str) return str;
      return parent[str]= findParent(parent[str], parent);
    }
  
    int numSimilarGroups(vector<string>& strs){
        unordered_map<string,string> parent;
        unordered_map<string,unordered_set<string>> uni;
      
        // create disjoint sets
        for(auto &str: strs)
          parent[str]= str;
        
        // take union of similar elements
        for(int i=0; i<strs.size()-1; ++i){
          string s1= strs[i];
          for(int j=i+1; j<strs.size(); ++j){
            string s2= strs[j];
            if(isSimilar(s1, s2)){
              parent[findParent(s1, parent)]= findParent(s2, parent);
            }
          }
        }
        
        // create union set
        for(auto &str: strs){
          uni[findParent(str, parent)].insert(str);
        }
      
        int ans= 0;
        for(auto &it: uni) ans++;
      
        return ans;
    }
};