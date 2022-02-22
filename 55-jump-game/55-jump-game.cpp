class Solution {
public:
    bool solve(int i, vector<int> &nums, int n){
        if(i==n-1) return true;
        
        if(nums[i]==0) return false;
        
        for(int j=1; j<=nums[i]; j++){
            if(solve(i+j, nums, n)) return true;
        }
        
        return false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
    
        vector<bool> dp(n);
        dp[n-1]= true;
        
        for(int i=n-2; i>=0; i--){
            if(nums[i]==0) dp[i]=false;
            else{
                for(int j=1; j<=nums[i]; j++){
                    if(dp[i+j]){
                        dp[i]=true;
                        break;
                    }
                }
                if(dp[i]!=true)
                    dp[i]= false;
            }
        }
        
        return dp[0];
    }
};