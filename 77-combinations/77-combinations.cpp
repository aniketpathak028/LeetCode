class Solution {
public:
    void findCombinations(int i, int n, int k, int idx, vector<int> &perm, vector<vector<int>> &ans){
      if(i>k){
        ans.push_back(perm);
        return;
      }
      
      for(int num= idx; num<=n; ++num){
          perm.push_back(num);
          findCombinations(i+1, n, k, num+1, perm, ans);
          perm.pop_back();
      }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> perm;
        findCombinations(1, n, k, 1, perm, ans);
        return ans;
    }
};