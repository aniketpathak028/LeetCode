class Solution {
public:
    int missingNumber(vector<int>& nums) {
        map<int,int> mp;
        int n= nums.size();
        for(auto num: nums) mp[num]++;
        for(int i=0; i<=n; ++i) if(!mp[i]) return i;
        return -1;
    }
};