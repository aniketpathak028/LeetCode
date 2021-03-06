class Solution {
public:
    void findPermutation(int i, vector<int> &perm, vector<int> &nums, vector<int> &vis, vector<vector<int>> &ans){
      // base-case
      if(i==nums.size()) // i exceeds the number of elements
      {
        ans.push_back(perm);
        return;
      }
      
      unordered_set<int> set;
      
      for(int j=0; j<nums.size(); ++j){
        if(!vis[j] && !set.count(nums[j])){
          perm.push_back(nums[j]);
          vis[j]= 1;
          findPermutation(i+1, perm, nums, vis, ans);
          vis[j]= 0;
          perm.pop_back();
          set.insert(nums[j]);
        }
      }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>> ans;
        vector<int> perm;
        vector<int> vis(n, 0);
        findPermutation(0, perm, nums, vis, ans);
        return ans;
    }
};