class Solution {
public:
    void findCominations(int i, int idx, int n, int k, vector<int> &comb, vector<vector<int>> &ans){
      // base-case
      if(i>k){
        ans.push_back(comb);
        return;
      }
      
      // iterate from idx to n and choose an element
      for(int j=idx; j<=n; ++j){ 
        comb.push_back(j); // push the element into the combination
        findCominations(i+1, j+1, n, k, comb, ans); // find other permutations from idx+1
        comb.pop_back(); // remove the element
      }
    }
  
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb;
        findCominations(1, 1, n, k, comb, ans);
        return ans;
    }
};