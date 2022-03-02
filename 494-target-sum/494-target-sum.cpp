class Solution {
public:
    int solve(int i, vector<int> &nums, int tar){
        if(i==0){
            if(nums[0]==0 && tar==0) return 2;
            if(tar==nums[0] || tar==-nums[0]) return 1;
            return 0;
        }
        
        int plus = solve(i-1, nums, tar+nums[i]);
        int minus = solve(i-1, nums, tar-nums[i]);
        
        return plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        return solve(n-1, nums, target);
    }
};