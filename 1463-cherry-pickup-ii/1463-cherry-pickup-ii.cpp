class Solution {
public: 
    int cherryPickup(vector<vector<int>>& grid) {
        int c = grid[0].size()-1;
        int r = grid.size()-1;
        vector<vector<int>> prev(vector<vector<int>>(c+1, vector<int>(c+1, 0)));
        
        // base-case intialization
        for(int j1=0; j1<=c; j1++){
            for(int j2=0; j2<=c; j2++){
                if(j1==j2) prev[j1][j2]= grid[r][j1];
                else prev[j1][j2] = grid[r][j1]+grid[r][j2];
            }
        }
        
        for(int i=r-1; i>=0; i--){
            vector<vector<int>> curr(vector<vector<int>>(c+1, vector<int>(c+1, 0)));
            for(int j1=0; j1<=c; j1++){
                for(int j2=0; j2<=c; j2++){
                    int maxi = 0;
                    for(int dj1=-1; dj1<=1; dj1++){
                    for(int dj2=-1; dj2<=1; dj2++){
                        if (j1 == j2){
                            if(j1+dj1>=0  && j1+dj1<=c && j2+dj2>=0 && j2+dj2<=c){
                                maxi = max(maxi, prev[j1 + dj1][j2 + dj2] + grid[i][j1]);
                            }
                        }
                        else
                        if(j1+dj1>=0  && j1+dj1<=c && j2+dj2>=0 && j2+dj2<=c)
                            maxi = max(maxi, prev[j1 + dj1][j2 + dj2] + grid[i][j1] + grid[i][j2]);
                    }
                }
                curr[j1][j2]= maxi;
                }
            }
            prev= curr;
        }
        
        return prev[0][c];
    }
};