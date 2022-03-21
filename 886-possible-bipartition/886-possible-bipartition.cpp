class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n+1];
        for(auto it: dislikes){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> grp(n+1, -1);
        
        for(int i=1; i<=n; ++i){
            if(grp[i]==-1){
                queue<int> q;
                q.push(i);
                grp[i]=1;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(auto it: adj[node]){
                        if(grp[it]==-1){
                            grp[it]= grp[node]==1 ? 0 : 1;
                            q.push(it);
                        }
                        else if(grp[node]==grp[it]) return false;
                    }
                }
            }
        }
        
        return true;
    }
};