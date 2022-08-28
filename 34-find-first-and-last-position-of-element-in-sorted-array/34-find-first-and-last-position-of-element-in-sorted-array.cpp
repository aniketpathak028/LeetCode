class Solution {
public:
    int firstOccurence(vector<int> &nums, int tar){
        int s= 0, e= nums.size()-1, mid, res= -1;
        while(s<=e){
            mid= s + (e-s)/2;
            if(nums[mid]==tar){
                res= mid;
                e= mid-1;
            }
            else if(nums[mid]<tar) s= mid+1;
            else e= mid-1;
        }
        return res;
    }
    
    int lastOccurence(vector<int> &nums, int tar){
        int s= 0, e= nums.size()-1, mid, res= -1;
        while(s<=e){
            mid= s + (e-s)/2;
            if(nums[mid]==tar){
                res= mid;
                s= mid+1;
            }
            else if(nums[mid]<tar) s= mid+1;
            else e= mid-1;
        }
        return res;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(firstOccurence(nums, target));
        ans.push_back(lastOccurence(nums,target));
        return ans;
    }
};