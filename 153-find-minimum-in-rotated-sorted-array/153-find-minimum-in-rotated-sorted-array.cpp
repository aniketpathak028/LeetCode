class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size() - 1, mid;
        int prev, next, n = nums.size();
        if(n==1) return nums[0];
        if(nums[start]<nums[end])
            return nums[start];
        while(start<=end){
            mid = start + (end - start) / 2;
            prev = (mid + n - 1) % n, next = (mid + 1) % n;
            if(nums[mid]<nums[prev] && nums[mid]<nums[next])
                return nums[mid];
            if(nums[mid]<nums[end])
                end = mid - 1;
            else
                start = mid + 1;
        }
        return -1;
    }
};