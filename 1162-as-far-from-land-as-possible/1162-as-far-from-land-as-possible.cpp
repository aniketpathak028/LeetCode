class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n= grid.size(), m= grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> res(n, vector<int>(m));
        
        // push all the land cells in queue
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
               if(grid[i][j]){
                   q.push({i,j});
                   res[i][j]= 0;
               }else{
                   res[i][j]= INT_MAX;
               }
            }
        }
        
        vector<vector<int>> dir= {{-1,0}, {1,0}, {0,-1}, {0,1}};
        
        while(!q.empty()){
            auto node= q.front();
            int i= node.first, j= node.second;
            q.pop();
            for(auto &it: dir){
                if(i+it[0]>=0 && i+it[0]<n && j+it[1]>=0 && j+it[1]<m && grid[i+it[0]][j+it[1]]==0 && res[i][j]+1<res[i+it[0]][j+it[1]]){
                    res[i+it[0]][j+it[1]]= 1+res[i][j];
                    q.push({i+it[0],j+it[1]});
                }
            }
        }
        
        int ans= INT_MIN;
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(!grid[i][j]){
                    ans= max(ans, res[i][j]);
                }
            }
        }
        
        if(ans==INT_MAX || ans==INT_MIN) return -1;
        else return ans;
    }
};