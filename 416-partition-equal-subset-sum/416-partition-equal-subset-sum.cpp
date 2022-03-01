class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return false;
        int sum = 0; 
        for(auto i:nums) sum+=i;
        if(sum&1) return false;
        else{
            sum= sum/2;
            vector<vector<bool>> dp(n, vector<bool>(sum+1, false));
            vector<bool> curr(sum+1, false);
            vector<bool> prev(sum+1, false);
            
            // base case initialization
            for(int i=0; i<n; i++) prev[0]= true;
            if(sum>=nums[0]) prev[nums[0]]= true;

            for(int i=1; i<n; i++){
                for(int j=1; j<=sum; j++){
                    bool not_pick = prev[j];
                    bool pick = false;
                    if(nums[i]<=j) pick= prev[j-nums[i]];
                    curr[j]= pick|not_pick;
                }
                prev= curr;
            }
            return prev[sum];
        }
    }
};