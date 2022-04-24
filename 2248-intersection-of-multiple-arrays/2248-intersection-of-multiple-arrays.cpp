class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int,int> count;
        for(auto it: nums)
          for(auto num: it) count[num]++;
        vector<int> ans;
        for(auto it: count) if(it.second==nums.size()) ans.push_back(it.first);
        return ans;
    }
};