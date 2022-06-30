class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(), nums.end());
        int mid= n/2, min_moves= 0;
        if(n%2){
          for(auto &num: nums) min_moves+= abs(num-nums[mid]);
        }else{
          for(auto &num: nums) min_moves+= abs(num-nums[mid]);
        }
      return min_moves;
    }
};