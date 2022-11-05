class Solution {
public:
    
    int countVowelStrings(int n) {
        vector<char> vowels= {'a', 'e', 'i', 'o', 'u'};
        vector<vector<int>> dp(6, vector<int>(n+1, -1));
        // base-case
        for(int i=0; i<=5; ++i){
            for(int j=0; j<=n; ++j){
                if(i==5) dp[i][j]= 0;
                if(j==0) dp[i][j]= 1;
            }
        }
        // tabulation
        for(int i= 4; i>=0; --i){
            for(int j=1; j<=n; ++j){
                dp[i][j]= dp[i][j-1]+dp[i+1][j];
            }
        }
        return dp[0][n];
    }
};