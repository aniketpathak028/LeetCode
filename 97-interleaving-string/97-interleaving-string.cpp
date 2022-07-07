class Solution {
public:
    bool solve(int i, int j, int k, string &s1, string &s2, string &s3, vector<vector<vector<int>>> &dp){
      if(i==s1.size() && j==s2.size() && k==s3.size()) return true;
      
      if(dp[i][j][k]!=-1) return dp[i][j][k];
      
      // if char matched to both first and second string
      if(s3[k]==s1[i] && s3[k]==s2[j]) return dp[i][j][k]= solve(i+1, j, k+1, s1, s2, s3, dp) || solve(i, j+1, k+1, s1, s2, s3, dp);
      
      if(s3[k]==s1[i]) return dp[i][j][k]= solve(i+1, j, k+1, s1, s2, s3, dp);
      if(s3[k]==s2[j]) return dp[i][j][k]= solve(i, j+1, k+1, s1, s2, s3, dp);
      
      return dp[i][j][k]= false;
    }
  
    bool isInterleave(string s1, string s2, string s3) {
        int len1= s1.size(), len2= s2.size(), len3= s3.size();
        vector<vector<vector<int>>> dp(len1+1, vector<vector<int>>(len2+1, vector<int>(len3+1, -1)));
        if(len3==len1+len2) return solve(0, 0, 0, s1, s2, s3, dp);
        return false;
    }
};