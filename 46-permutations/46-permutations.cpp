class Solution {
public:
    void findPermutation(int i, vector<int> &perm, vector<int> &nums, vector<int> &vis, vector<vector<int>> &ans){
      // base-case
      if(i==nums.size()) // when i exceeds the number of elements
      {
        ans.push_back(perm);
        return;
      }
      
      for(int j=0; j<nums.size(); ++j){
        if(!vis[j]){ // check if this eleements has already been included or not
          vis[j]= 1;
          perm.push_back(nums[j]);
          findPermutation(i+1, perm, nums, vis, ans);
          perm.pop_back();
          vis[j]= 0;
        }
      }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>> ans;
        vector<int> vis(n, 0); // visited array
        vector<int> perm;
        findPermutation(0, perm, nums, vis, ans);
        return ans;
    }
};