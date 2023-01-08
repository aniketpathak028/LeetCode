class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans= 2, size= points.size();
        if(size<2) return size;
        for(int i=0; i<size-1; ++i){
            for(int j=i+1; j<size; ++j){
                int count= 2;
                for(int k=i+1; k<j; ++k){
                    if((points[j][1]-points[i][1])*(points[k][0]-points[i][0])==(points[j][0]-points[i][0])*(points[k][1]-points[i][1])) count++;
                }
                ans= max(ans, count);
            }
        }
        return ans;
    }
};