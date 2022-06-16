class Solution {
public:
    int countSubstrings(string s) {
        int n= s.size(), cnt= 0;
        vector<vector<bool>> dp(n, vector<bool>(n));
        for(int g=0; g<n; ++g){
          int i=0, j= g;
          while(j<n){
            if(g==0) dp[i][j]= 1;
            else if(g==1) dp[i][j]= s[i]==s[j];
            else dp[i][j]= s[i]==s[j] && dp[i+1][j-1];
            if(dp[i++][j++]) cnt++;
          }
        }
      return cnt;
    }
};