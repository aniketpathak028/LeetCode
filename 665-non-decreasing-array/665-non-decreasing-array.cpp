class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
       int count= 0;
       for(int i=0; i<nums.size()-1; ++i){
         if(count>1) return false;
         if(i==0){
           if(nums[i]>nums[i+1]){
             count++;
             nums[i]= nums[i+1]-1;
           } 
         }else if(nums[i]>nums[i+1]){
           if(nums[i-1]==nums[i+1]) nums[i]= nums[i-1];
           else if(nums[i-1]+1>nums[i+1]) nums[i+1]= nums[i]+1;
           else nums[i]= nums[i-1]+1;
           count++;
         }
       }
      if(count>1) return false;
      return true;
    }
};