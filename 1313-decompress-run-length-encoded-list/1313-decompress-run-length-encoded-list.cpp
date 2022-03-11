class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans;
        for(int i=0; i<nums.size(); ++i){
           if(!(i & 1)){
               while(nums[i]--){
                   ans.push_back(nums[i+1]);
               }
           }
        } 
        return ans;
    }
};