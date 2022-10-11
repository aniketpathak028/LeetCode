class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n= mat.size(), m= mat[0].size();
        
        queue<pair<int,int>> q;
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(!mat[i][j]) q.push({i,j});
                else mat[i][j]= INT_MAX;
            }
        }
        
        vector<vector<int>> dir= {{-1,0}, {0,-1}, {0,1}, {1,0}};
        
        while(!q.empty()){
            auto node= q.front();
            q.pop();
            int i= node.first, j= node.second;
            for(auto &it: dir){
                if(i+it[0]>=0 && i+it[0]<n && j+it[1]>=0 && j+it[1]<m && mat[i+it[0]][j+it[1]]>0 && mat[i][j]+1<mat[i+it[0]][j+it[1]]){
                    mat[i+it[0]][j+it[1]]= mat[i][j]+1;
                    q.push({i+it[0],j+it[1]});
                }
            }
        }
        
        return mat;
    }
};