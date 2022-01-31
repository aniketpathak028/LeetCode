class Solution {
public:
    void findSubsets(int index, vector<int>& nums, vector<vector<int>> &ans, vector<int> subset){
        ans.push_back(subset);
        
        for(int i=index; i<nums.size(); i++){
            if(i!=index && nums[i]==nums[i-1]) continue;
            subset.push_back(nums[i]);
            findSubsets(i+1, nums, ans, subset);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        findSubsets(0, nums, ans, subset);
        return ans;
    }
};