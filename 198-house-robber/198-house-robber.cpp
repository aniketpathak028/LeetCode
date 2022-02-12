class Solution {
public:
    int solve(vector<int> &nums, int n, vector<int> &dp)
    {
        if (n <= -1) return 0;

        if(dp[n]!=-1)
            return dp[n];

        int l = nums[n] + solve(nums, n - 2, dp);

        int r = solve(nums, n - 1, dp);

        return dp[n]=max(l, r);
    }
    int rob(vector<int>& nums) {
         int size= nums.size();
    vector<int> dp(size, -1);
    solve(nums, size-1, dp);
         return dp[size-1];
    }
};