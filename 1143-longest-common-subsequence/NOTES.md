**Recurrence**
​
```
int solve(int idx1, int idx2, string &s1, string &s2){
if(idx1<0 || idx2<0) return 0; // if any of the string length is 0 return LCS as 0
if(s1[idx1]==s2[idx2]) return 1+solve(idx1-1, idx2-1, s1, s2);
return max(solve(idx1-1, idx2, s1, s2), solve(idx1, idx2-1, s1, s2));
}
int longestCommonSubsequence(string text1, string text2) {
int n= text1.size(), m= text2.size();
return solve(n-1, m-1, text1, text2);
}
```
​
**Memoization**
​
```
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
```
​
**Tabulation**
​
​
​
**Space-Optimization**
​
​
int longestCommonSubsequence(string text1, string text2) {
vector<int> curr(text2.size()+1, 0), prev(text2.size()+1, 0);
​
for(int i=1; i<=text1.size(); i++){
for(int j=1; j<=text2.size(); j++){
if(text1[i-1]==text2[j-1]) curr[j]= 1+prev[j-1];
else curr[j]= max(prev[j], curr[j-1]);
}
prev= curr;
}
return prev[text2.size()];
}