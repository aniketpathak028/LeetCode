class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return false;
        int sum = 0; 
        for(auto i:nums) sum+=i;
        if(sum&1) return false;
        else{
            sum= sum/2;
            vector<vector<bool>> dp(n, vector<bool>(sum+1, false));
            // base case initialization
            for(int i=0; i<n; i++) dp[i][0]= true;
            if(sum>=nums[0]) dp[0][nums[0]]= true;

            for(int i=1; i<n; i++){
                for(int j=1; j<=sum; j++){
                    bool not_pick = dp[i-1][j];
                    bool pick = false;
                    if(nums[i]<=j) pick= dp[i-1][j-nums[i]];
                    dp[i][j]= pick||not_pick;
                }
            }
            return dp[n-1][sum];
        }
    }
};