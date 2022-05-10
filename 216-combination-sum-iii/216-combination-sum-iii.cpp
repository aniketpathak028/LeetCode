class Solution {
public:
    void solve(int i, int sum, int k, vector<int> &comb, vector<vector<int>> &ans){
      // if the target sum==0 and k digits are used
      if(sum==0 && k==0){
        ans.push_back(comb);
        return;
      }
      
      if(i>9) return; // if value of i exceeds 9
    
      if(sum==0 || k==0) return; // if the sum is exhausted or k digits have already been used
      
      // pick 
      if(i<=sum){
        comb.push_back(i);
        solve(i+1, sum-i, k-1, comb, ans);
        comb.pop_back();
      } 
      
      // not-pick
      
      solve(i+1, sum, k, comb, ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> comb;
        solve(1, n, k, comb, ans);
        return ans;
    }
};