// hashmap to keep track of word positions
unordered_map<string,int> mpp;
for(int i=0; i<n; ++i) mpp[words[i]]= i+1;
// try all indices as starting index to find maximum word chain
int maxi= 1;
for(int i=0; i<n; ++i) maxi= max(maxi, solve(i, words, mpp));
return maxi;
}
```
​
**Memoization**
​
```
int solve(int i, vector<string> &words, unordered_map<string,int> &mpp, vector<int> &dp){
// if dp contains the ans return
if(dp[i]!=-1) return dp[i];
// if no other word is found shortest word chain will be of length 1
int len= 1;
string str= words[i];
for(int j=0; j<str.size(); ++j){
string new_str= str;
new_str.erase(j, 1); // erase the character at index j
if(mpp[new_str]>0){ // if the new word exists, find solve ahead and take the maximum
len= max(1+solve(mpp[new_str]-1, words, mpp, dp), len);
}
}
// return maximum length of word chain possible at index i
return dp[i]= len;
}
int longestStrChain(vector<string>& words) {
int n= words.size();
// hashmap to keep track of word positions
unordered_map<string,int> mpp;
for(int i=0; i<n; ++i) mpp[words[i]]= i+1;
// initialize dp vector
vector<int> dp(n, -1);
// try all indices as starting index to find maximum word chain
int maxi= 1;
for(int i=0; i<n; ++i) maxi= max(maxi, solve(i, words, mpp, dp));
return maxi;
}
```