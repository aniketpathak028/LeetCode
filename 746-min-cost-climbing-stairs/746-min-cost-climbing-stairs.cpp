class Solution {
public:
    int solve(vector<int> &cost, vector<int> &dp, int ind){
        if(ind<0) return 0;
        if(ind==0) return cost[0];
        
        if(dp[ind]!=-1) return dp[ind];
        
        int left = solve(cost, dp, ind-1) + cost[ind];
        if(ind>0){
            int right = solve(cost, dp, ind-2) + cost[ind];
            return dp[ind] = min(left, right);
        }
        return dp[ind] = left;
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        vector<int> dp(size, -1);
        return min(solve(cost, dp, size-1), solve(cost, dp, size-2));
        
    }
};