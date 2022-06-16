class Solution {
public:
    string longestPalindrome(string s) {
        int start, end;
        int n= s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        for(int g=0; g<n; ++g){
          int i= 0, j= g;
          while(j<n){
            if(g==0){
             dp[i][j]= 1; 
            } else if(g==1){
              dp[i][j]= s[i]==s[j];
            } else{
              dp[i][j]= (s[i]==s[j]) && dp[i+1][j-1];
            }
            if(dp[i][j]){
              start= i, end= j;
            }
            i++; j++;
          }
        }
      return s.substr(start, end-start+1);
    }
};