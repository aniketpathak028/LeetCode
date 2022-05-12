class Solution {
public:
    void findPermutations(int i, vector<int> &nums, vector<vector<int>> &ans){
      if(i==nums.size()){
        ans.push_back(nums);
        return;
      }
      
      for(int idx=i; idx<nums.size(); idx++){
        swap(nums[i], nums[idx]);
        findPermutations(i+1, nums, ans);
        swap(nums[i], nums[idx]);
      }
    }
  
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        findPermutations(0, nums, ans);
        return ans;
    }
};