class Solution {
public:
    int mod= 1e9+7;
    long long solve(int i, int prev, int n, unordered_map<int,vector<int>> &mpp, vector<vector<int>> &dp){
      if(i==n) return 1;
      
      if(dp[i][prev]!=-1) return dp[i][prev];
      
      long long cnt= 0;
      // iterate all possible charcters for the last character
      for(auto it: mpp[prev]){
        cnt+= solve(i+1, it, n, mpp, dp)%mod;
      }
      
      return dp[i][prev]= cnt%mod;
    }
  
    int countVowelPermutation(int n) {
        // mapping of characters with all the characters that can follow
        unordered_map<int,vector<int>> mpp;
        mpp[0]= {1};
        mpp[1]= {0, 2};
        mpp[2]= {0, 1, 3, 4};
        mpp[3]= {2, 4};
        mpp[4]= {0};
      
        vector<vector<int>> dp(n+1, vector<int>(5, -1));
      
        long long ans= 0;
        for(int i=0; i<5; ++i){
          ans+= solve(1, i, n, mpp, dp)%mod;
        }
        
        return ans%mod;
    }
};