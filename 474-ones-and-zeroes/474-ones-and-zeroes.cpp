class Solution {
public:
    // tabulation
    int findMaxForm(vector<string>& strs, int m, int n) {
        int s= strs.size();
        // dp vector
        vector<vector<vector<int>>> dp(s+1, vector<vector<int>>(n+1, vector<int>(m+1, 0)));
        // tabulation
        for(int i=s-1; i>=0; --i){
         for(int j=0; j<=n; ++j){
           for(int k=0; k<=m; ++k){
              if(j==0 && k==0) continue; // base case both n==0 && m==0
              // calculate the no of 0's and 1's in the current string
              int cnt_0= 0, cnt_1= 0;
              for(auto ch: strs[i]) cnt_1+= ch-'0';
              cnt_0= strs[i].size()- cnt_1;
    
              int pick, notPick;
              pick= notPick= INT_MIN;

              // pick 
              if(cnt_0<=k && cnt_1<=j) pick= 1+dp[i+1][j-cnt_1][k-cnt_0];
              // notpick
              notPick= dp[i+1][j][k];

              dp[i][j][k]= max(pick, notPick);
           }
         } 
        }
      
      return dp[0][n][m];
    }
};