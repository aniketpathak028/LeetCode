class Solution {
public:
    string findParent(string acc, map<string,string> &parent){
      if(acc==parent[acc]) return acc;
      return parent[acc]= findParent(parent[acc], parent);
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string,string> parent;
        map<string,string> owner;
        map<string, set<string>> uni;
        
        // create disjoint sets for all accounts
        for(int i=0; i<accounts.size(); ++i){
          string own= accounts[i][0];
          for(int j=1; j<accounts[i].size(); ++j){
            parent[accounts[i][j]]= accounts[i][j];
            owner[accounts[i][j]]= own;
          }
        }
      
        // perform union of same accounts
        for(int i=0; i<accounts.size(); ++i){
          string par= findParent(accounts[i][1], parent);
          for(int j=2; j<accounts[i].size(); ++j){
            parent[findParent(accounts[i][j], parent)]= par;
          }
        }
      
        // add the accnts to union set
        for(auto acc: accounts){
          for(int j=1; j<acc.size(); ++j) uni[findParent(acc[j], parent)].insert(acc[j]);
        }
      
        // create ans vector
        vector<vector<string>> ans;
        for(auto &it: uni){
          vector<string> acc;
          acc.push_back(owner[it.first]);
          for(auto &s: it.second) acc.push_back(s); 
          ans.push_back(acc);
        }
      
      return ans;
    }
};