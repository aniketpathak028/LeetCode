class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& candidates, int target, int i, vector<int> &com){
        if(i==candidates.size()){
            if(target==0){
                ans.push_back(com);
            }
            return;
        }
        
        if(target>=candidates[i]){
            com.push_back(candidates[i]);
            solve(candidates, target-candidates[i], i, com);
            com.pop_back();
        }
       
        solve(candidates, target, i+1, com);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> com;
        solve(candidates, target, 0, com);
        return ans;
    }
};