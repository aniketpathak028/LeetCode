class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n= cardPoints.size(), sum= 0;
        vector<int> prefix(n);
        for(int i=0; i<n; ++i){
          sum+= cardPoints[i];
          prefix[i]= sum;
        } 
        int ans= INT_MIN;
        if(k==n) return sum;
        for(int i=0, j=n-k-1; j<n; ++i, ++j){
          int curr_sum= sum-(prefix[j]-prefix[i]+cardPoints[i]);
          ans= max(ans, curr_sum);
        }
        return ans;
    }
};