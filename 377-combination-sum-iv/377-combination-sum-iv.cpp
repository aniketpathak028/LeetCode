class Solution {
public:
    int findCombinations(int target, vector<int> &nums, vector<int> &dp){
      // base-case
      if(target==0) return 1;
      
      if(dp[target]!=-1) return dp[target];
      
      int res= 0;
      
      for(int j=0; j<nums.size(); ++j){
        if(nums[j]<=target){
          res+= findCombinations(target-nums[j], nums, dp);
        }
      }
      
      return dp[target]= res;
    }
  
    int combinationSum4(vector<int>& nums, int target) {
        int n= nums.size();
        vector<int> dp(target+1, -1);
        return findCombinations(target, nums, dp);
    }
};