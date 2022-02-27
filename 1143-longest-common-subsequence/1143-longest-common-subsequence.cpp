class Solution {
public:
    int solve(int i, int j, string s1, string s2, vector<vector<int>> &dp){
        // base-case
        if(i<0 || j<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s1[i]==s2[j]) return dp[i][j]= 1+solve(i-1, j-1, s1, s2, dp);
        else return dp[i][j]= max(solve(i-1, j, s1, s2, dp), solve(i, j-1, s1, s2, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        // return solve(n1-1, n2-1, text1, text2, dp);
        
        // base-case 
        // for(int i=; i<n1; i++){
        //     if(text1[i]==text2[0]) dp[i][0]=1;
        //     else {
        //         if(i>0 && dp[i-1][0]==1) dp[i][0] = 1;
        //         else dp[i][0] = 0;
        //     }
        // }
        // for(int j=0; j<n2; j++){
        //     if(text2[j]==text1[0]) dp[0][j]=1;
        //     else {
        //         if(j>0 && dp[0][j-1]==1) dp[0][j-1] = 1;
        //         else dp[0][j]=0;
        //     }
        // }
        
        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(text1[i-1]==text2[j-1]) dp[i][j]= 1+dp[i-1][j-1];
                else dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[n1][n2];
    }
};