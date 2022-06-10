class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int first= -1, last= -1;
        // find first occurence
        int s= 0, e= nums.size()-1, m;
        while(s<=e){
          m= s+(e-s)/2;
          if(nums[m]==target){
            first= m;
            e= m-1;
          }
          else if(nums[m]<target) s= m+1;
          else e= m-1;
        }
        ans.push_back(first);
      
        // find last occurence
        s= 0, e= nums.size()-1;
        while(s<=e){
          m= s+(e-s)/2;
          if(nums[m]==target){
            last= m;
            s= m+1;
          }
          else if(nums[m]<target) s= m+1;
          else e= m-1;
        }
        ans.push_back(last);
        return ans;
    }
};