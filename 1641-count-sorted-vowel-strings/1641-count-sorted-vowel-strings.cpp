class Solution {
public:
    int solve(int i, int n, vector<char> &vowels, vector<vector<int>> &dp){
        // base-case
        if(n==0) return 1;
        if(i==vowels.size()) return 0;
        
        if(dp[i][n]!=-1) return dp[i][n];
        
        return dp[i][n]= solve(i, n-1, vowels, dp)+solve(i+1, n, vowels, dp);
    }
    
    int countVowelStrings(int n) {
        vector<char> vowels= {'a', 'e', 'i', 'o', 'u'};
        vector<vector<int>> dp(5, vector<int>(n+1, -1));
        return solve(0, n, vowels, dp);
    }
};