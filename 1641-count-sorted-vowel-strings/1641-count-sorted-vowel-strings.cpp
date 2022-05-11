class Solution {
public:
    int countVowelStrings(int n) {
        
        string vowels= "aeiou"; // all vowels in lexicographically sorted order
        
        vector<vector<int>> dp(5, vector<int>(n+1)); // dp vector
      
        // base-case
        for(int i=0; i<5; ++i) dp[i][0]= 1; // if n==0 return 1
      
        // tabulation
        for(int i=4; i>=0; --i){
          for(int j=1; j<=n; ++j){
            int pick= 0, notPick= 0;
            // pick i.e. pick this alphabet
            pick= dp[i][j-1];
            // notPick i.e. skip this alphabet
            if(i<4) notPick= dp[i+1][j];
            
            dp[i][j]= pick+notPick;
          }
        }
      
        return dp[0][n]; // return all strings possible starting from 0 index and of n length
    }
};