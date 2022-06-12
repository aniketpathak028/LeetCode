class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int left= 0, right= 0, n= nums.size(), maxi= INT_MIN;
        unordered_set<int> set; 
        vector<int> prefix(n);
        int sum= 0;
        for(int i=0; i<n; ++i){
          sum+= nums[i];
          prefix[i]= sum;
        }
        while(right<n){
          if(set.count(nums[right]))
            set.erase(nums[left++]);
          else if(!set.count(nums[right])){
            set.insert(nums[right]);
            maxi= max(maxi, prefix[right++]-prefix[left]+nums[left]);
          }
        }
      return maxi;
    }
};