class Solution {
public:
    int solve(int i, int lane, vector<int> &obstacles, vector<vector<int>> &dp){
        // base-case
        if(i==obstacles.size()-1) return 0;
        
        if(dp[i][lane]!=-1) return dp[i][lane];
        
        if(obstacles[i+1]==lane){
            if(lane==1){
                if(obstacles[i]==2){
                    return dp[i][lane]=1+solve(i+1, 3, obstacles, dp);
                }else if(obstacles[i]==3){
                    return dp[i][lane]=1+solve(i+1, 2, obstacles, dp);
                }else{
                    return dp[i][lane]=1+min(solve(i+1, 3, obstacles, dp),solve(i+1, 2, obstacles, dp));
                }
            }
            else if(lane==2){
               if(obstacles[i]==1){
                    return dp[i][lane]=1+solve(i+1, 3, obstacles, dp);
                }else if(obstacles[i]==3){
                    return dp[i][lane]=1+solve(i+1, 1, obstacles, dp);
                }else{
                    return dp[i][lane]=1+min(solve(i+1, 1, obstacles, dp),solve(i+1, 3, obstacles, dp));
                }
            }
            else{
                if(obstacles[i]==2){
                    return dp[i][lane]=1+solve(i+1, 1, obstacles, dp);
                }else if(obstacles[i]==1){
                    return dp[i][lane]=1+solve(i+1, 2, obstacles, dp);
                }else{
                    return dp[i][lane]=1+min(solve(i+1, 1, obstacles, dp),solve(i+1, 2, obstacles, dp));
                }   
            }
        }
        else return dp[i][lane]=solve(i+1, lane, obstacles, dp);
    }
    int minSideJumps(vector<int>& obstacles) {
        int n= obstacles.size();
        vector<vector<int>> dp(n+1, vector<int>(4, -1));
        return solve(0, 2, obstacles, dp);
    }
};