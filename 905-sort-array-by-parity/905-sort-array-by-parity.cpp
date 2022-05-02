class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        for(int i=0; i<nums.size()-1; ++i){
          if(nums[i]%2){
            int flag= 0;
            for(int j=i+1; j<nums.size(); ++j){
              if(!(nums[j]%2)){
                swap(nums[i], nums[j]);
                flag= 1;
                break;
              } 
            }
            if(flag==0) break;
          }
        }
      return nums;
    }
};