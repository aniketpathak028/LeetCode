class Solution {
public:
    int lis(int i, vector<int> &nums, vector<int> &dp){
        if(i==0) return 1;
        if(dp[i]!=-1) return dp[i];
        int ans=1;
        for(int j=0; j<i; j++){
            if(nums[j]<nums[i]) ans= max(ans, 1+lis(j, nums, dp));
        }
        return dp[i]=ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int ans=INT_MIN;
        int n= nums.size();
        vector<int> dp(n, -1);
        for(int i=0; i<n; i++) ans= max(ans, lis(i, nums, dp));
        return ans;
    }
};