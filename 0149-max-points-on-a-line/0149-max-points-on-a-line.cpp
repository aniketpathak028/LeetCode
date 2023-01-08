class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans= 0;
        for(auto &p1: points){
            unordered_map<double,int> mpp;
            double x1= p1[0], y1= p1[1];
            for(auto &p2: points){
                if(p2==p1) continue;
                double x2= p2[0], y2= p2[1];
                double slope;
                if(x2-x1==0) slope= INT_MAX;
                else slope= (y2-y1)/(x2-x1);
                mpp[slope]++;
                ans= max(ans, mpp[slope]);
            }
        }
        return ans+1;
    }
};