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
        int n= nums.size();
        vector<int> dp(n, -1);
        dp[0]=1;
        for(int i=1; i<n; i++){
            int ans=1;
            for(int j=0; j<i; j++){
                if(nums[j]<nums[i]) ans= max(ans, 1+dp[j]);
            }
            dp[i]=ans;
        }
        
        int maxi=INT_MIN;
        for(int i=0; i<n; i++) maxi= max(maxi, dp[i]);
        return maxi;
    }
};