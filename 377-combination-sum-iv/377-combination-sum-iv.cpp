class Solution {
public:
    int findCombinations(int target, vector<int> &nums, vector<int> &dp){
      // base-case
      if(target==0) return 1;
      
      // check if dp contains the answer already
      if(dp[target]!=-1) return dp[target];
      
      // iterate all elements in nums
      int res= 0;
      for(auto &num: nums){
        if(num<=target){
          res+= findCombinations(target-num, nums, dp);
        }
      }
      
      return dp[target]= res;
    }
  
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        return findCombinations(target, nums, dp);
    }
};