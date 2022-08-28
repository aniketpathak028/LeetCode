class Solution {
public:
    int binary__search(vector<int> &nums, int start, int end, int target){
        int mid;
        while(start<=end){
            mid= start+(end-start)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) start= mid+1;
            else end= mid-1;
        }
        return -1;
    }
    
    int findMinIndex(vector<int> &nums){
        int s= 0, e= nums.size()-1, mid, prev, next, n= nums.size();
        if(n==1 || nums[0]<nums[e]) return 0;
        while(s<=e){
            mid= s+(e-s)/2, prev= (mid+n-1)%n, next= (mid+1)%n;
            if(nums[mid]<nums[prev] && nums[mid]<nums[next]) return mid;
            else if(nums[mid]<nums[e]) e= mid-1;
            else s= mid+1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int minpos= findMinIndex(nums);
        
        if(!minpos) return binary__search(nums, 0, nums.size()-1, target);
        
        if(binary__search(nums, 0, minpos-1, target)!=-1) return binary__search(nums, 0, minpos-1, target);
        else return binary__search(nums, minpos, nums.size()-1, target);
    }
};