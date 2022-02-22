class Solution {
public:
    
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        
        // base-case 
        dp[n-1] = 0;
        
        for(int i=n-2; i>=0; i--){
            int mini=1e9;
            for(int j=1; j<=nums[i]; j++){
               if(i+j<=n-1) mini = min(mini, 1+dp[i+j]);
            }
            
            dp[i]= mini;
        }
        
        return dp[0];
    }
};