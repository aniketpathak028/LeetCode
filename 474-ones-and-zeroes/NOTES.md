# Recurrence
`
int solve(int i, vector<string> &str, int n, int m){
// base-case, when i goes out of bound OR we have used all the 1's and 0's
if(i==str.size() || (!m && !n)) return 0;
// calculate the no of 0's and 1's in the current string
int cnt_0= 0, cnt_1= 0;
for(auto ch: str[i]) cnt_1+= ch-'0';
cnt_0= str[i].size()- cnt_1;
int pick, notPick;
pick= notPick= INT_MIN;
// pick
if(cnt_0<=m && cnt_1<=n) pick= 1+solve(i+1, str, n-cnt_1, m-cnt_0);
// notpick
notPick= solve(i+1, str, n, m);
return max(pick, notPick);
}
int findMaxForm(vector<string>& strs, int m, int n) {
return solve(0, strs, n, m);
}
`
# Memoization