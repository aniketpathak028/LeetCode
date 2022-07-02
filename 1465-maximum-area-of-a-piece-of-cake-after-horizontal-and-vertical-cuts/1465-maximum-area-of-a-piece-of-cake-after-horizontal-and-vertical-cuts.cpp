class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int n= horizontalCuts.size(), m= verticalCuts.size();
        // sort both the cuts
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        // vectors to keep differences  
        priority_queue<long> hd, vd;
          
        for(int i=0; i<n; ++i){
          if(i==0) hd.push(horizontalCuts[0]);
          else hd.push(horizontalCuts[i]-horizontalCuts[i-1]);
        }
        hd.push(h-horizontalCuts[n-1]);
      
        for(int i=0; i<m; ++i){
          if(i==0) vd.push(verticalCuts[0]);
          else vd.push(verticalCuts[i]-verticalCuts[i-1]);
        }
        vd.push(w-verticalCuts[m-1]);
      
        long mod= 1e9+7;
      
        return ((hd.top()%mod)*(vd.top()%mod))%mod;
    }
};