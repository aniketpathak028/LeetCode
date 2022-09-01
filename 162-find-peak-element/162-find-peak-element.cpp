class Solution {
public:
    int findPeak(vector<int> &nums){
        int s= 0, n= nums.size(), e= n-1, mid;
        if(n==1) return 0;
        while(s<=e){
            mid= s+(e-s)/2;
            if(mid>0 && mid<n-1){
             if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]) return mid;
             else if(nums[mid]<nums[mid+1]) s= mid+1;
             else e= mid-1;
            }
            else if(mid==0){
                if(nums[0]>nums[1]) return 0;
                else return 1;
            }
            else if(mid==n-1){
                if(nums[n-1]>nums[n-2]) return n-1;
                else return n-2;
            }
        }
        return -1;
    }
    
    int findPeakElement(vector<int>& nums) {
        return findPeak(nums);
    }
};