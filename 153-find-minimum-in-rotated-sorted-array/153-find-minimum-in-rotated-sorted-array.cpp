class Solution {
public:
    int findMin(vector<int>& nums) {
        int s= 0, e= nums.size()-1, mid, next, prev, n= nums.size();
        if(n==1) return nums[0];
        while(s<=e){
            mid= s+(e-s)/2;
            next= (mid+1)%n, prev= (mid-1+n)%n;
            if(nums[mid]<nums[next] && nums[mid]<nums[prev]) return nums[mid];
            else if(nums[mid]<nums[e]) e= mid-1;
            else s= mid+1;
        }
        return -1;
    }
};