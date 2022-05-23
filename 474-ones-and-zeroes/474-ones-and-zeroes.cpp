class Solution {
public:
    int solve(int i, vector<pair<int,int>> &count, int m, int n, vector<vector<vector<int>>> &dp){
      // if m 0's or n 1's are used
      if(m==0 && n==0) return 0;
      // base-case, if i exceeds the str vector
      if(i==count.size()) return 0;
      
      // check if dp contains the ans
      if(dp[i][m][n]!=-1) return dp[i][m][n];
      
      int pick, notPick;
      pick= notPick= INT_MIN;
      
      int cnt_1= count[i].second, cnt_0= count[i].first;
      // pick 
      if(cnt_0<=m && cnt_1<=n)
        pick= 1+solve(i+1, count, m-cnt_0, n-cnt_1, dp);
      // notPick
      notPick= solve(i+1, count, m, n, dp);
      
      return dp[i][m][n]= max(pick, notPick);
    }
  
    int findMaxForm(vector<string>& strs, int m, int n) {
      int i= strs.size();
      // store the count of 0 and 1 in all strings 
      vector<pair<int,int>> count;
      for(auto s: strs){
        int cnt_1= 0, cnt_0= 0;
        // count all 0's and 1's
        for(int j=0; j<s.size(); ++j) cnt_1+= s[j]-'0';
        cnt_0 = s.size() - cnt_1;
        count.push_back({cnt_0, cnt_1});
      }
      
      vector<vector<vector<int>>> dp(i, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
      return solve(0, count, m, n, dp);
    }
};