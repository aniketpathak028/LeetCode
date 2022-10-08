class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n= image.size(), m= image[0].size();
        vector<pair<int,int>> neighbours= {{-1,0}, {1,0}, {0,-1}, {0,1}};
        queue<pair<int,int>> q;
        q.push({sr,sc});
        while(!q.empty()){
            auto node= q.front();
            int i= node.first, j= node.second;
            int col= image[i][j];
            image[i][j]= color;
            q.pop();
            for(auto &it: neighbours){
                if(i+it.first>=0 && i+it.first<n && j+it.second>=0 && j+it.second<m && image[i+it.first][j+it.second]==col && image[i+it.first][j+it.second]!=color){
                    q.push({i+it.first, j+it.second});
                }
            }
        }
        return image;
    }
};