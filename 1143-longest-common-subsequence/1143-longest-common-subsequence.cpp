class Solution {
public:
    int solve(int idx1, int idx2, string &s1, string &s2, vector<vector<int>> &dp){
      if(idx1<0 || idx2<0) return 0; // if any of the string length is 0 return LCS as 0
      
      if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
      
      if(s1[idx1]==s2[idx2]) return dp[idx1][idx2]= 1+solve(idx1-1, idx2-1, s1, s2, dp);
      
      return dp[idx1][idx2]= max(solve(idx1-1, idx2, s1, s2, dp), solve(idx1, idx2-1, s1, s2, dp));
    }
  
    int longestCommonSubsequence(string text1, string text2) {
        int n= text1.size(), m= text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n-1, m-1, text1, text2, dp);
    }
};