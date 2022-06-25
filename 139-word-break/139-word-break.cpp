class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string, int> mp;
        for(auto &word: wordDict) mp[word]++;
      
        vector<bool> dp(s.size()+1);
      
        dp[0]= true;
        
        for(int i=1; i<=s.size(); ++i){
          for(int j=0; j<i; ++j){
            bool left= dp[j];
            bool right= mp[s.substr(j, i-j)];
            if(left && right){
              dp[i]= 1;
              break;
            }
          }
        }
      
      return dp[s.size()];
    }
};