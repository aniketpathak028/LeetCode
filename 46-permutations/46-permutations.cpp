class Solution {
public:
    void findPermute(vector<int>& nums, map<int, int> &m, vector<vector<int>> &ans, vector<int>& ds){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        
        for(int i=0; i<nums.size(); i++){
            if(m[i]!=-1){
                ds.push_back(nums[i]);
                m[i]= -1;
                findPermute(nums, m, ans, ds);
                ds.pop_back();
                m[i]= 1;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        map<int, int> m;
        vector<vector<int>> ans;
        vector<int> ds;        
        findPermute(nums, m, ans, ds);
        return ans;
    }
};