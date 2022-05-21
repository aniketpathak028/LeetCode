class Solution {
public:
    int solve(int i, vector<int> &coins, int target, vector<vector<int>> &dp){
      // if i exceeds the coins vector
      if(i==coins.size()) return 1e9;
      // base-case
      if(target==0) return 0;
      
      // if dp contains ans
      if(dp[i][target]!=-1) return dp[i][target];
      
      int pick, notPick;
      pick= notPick= INT_MAX;
      
      // pick
      if(target>=coins[i]) pick= 1+solve(i, coins, target-coins[i], dp);
      
      // not-pick
      notPick= solve(i+1, coins, target, dp);
      
      return dp[i][target]= min(pick, notPick);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans= solve(0, coins, amount, dp);
        return ans>=1e9 ? -1 : ans;
    }
};