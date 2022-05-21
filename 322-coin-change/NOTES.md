int coinChange(vector<int>& coins, int amount) {
int n= coins.size();
// intialize dp
vector<vector<int>> dp(n, vector<int>(amount+1, -1));
// base-case
for(int i=0; i<=amount; i++) dp[0][i] = i%coins[0]==0 ? i/coins[0] : 1e9;
// tabulation
for(int i=1; i<n; i++){
for(int j=0; j<=amount; j++){
int pick, notPick;
pick=INT_MAX;
notPick= dp[i-1][j];
if(j>=coins[i]) pick= 1 + dp[i][j-coins[i]];
dp[i][j]= min(pick, notPick);
}
}
int ans = dp[n-1][amount];
if(ans>=1e9) return -1;
return ans;
}