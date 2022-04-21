vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
// create disjoint sets
MakeSet(accounts);
// take union of commom accounts
for(int i=0; i<accounts.size(); ++i){
string par= accounts[i][1];
for(int j=2; j<accounts[i].size(); ++j){
Union(par, accounts[i][j]);
}
}
// insert into union set
for(int i=0; i<accounts.size(); ++i){
for(int j=1; j<accounts[i].size(); ++j){
unions[FindPar(accounts[i][j])].insert(accounts[i][j]);
}
}
vector<vector<string>> ans;
for(auto it: unions){
string par= it.first, own= Owner[par];
vector<string> accnt;
accnt.push_back(own);
for(auto s: it.second){
accnt.push_back(s);
}
ans.push_back(accnt);
}
return ans;
}