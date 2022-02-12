class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
     int prev = nums[0];
    int prev2 = 0;
    for (int i = 1; i < n; i++)
    {
        int take = nums[i];
        if (i > 1)
            take += prev2;
        int not_take = prev;
        int curr = max(take, not_take);
        prev2 = prev;
        prev = curr;
    }
   return prev;
    }
};