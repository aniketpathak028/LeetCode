class Solution {
public:
    int findMinIndex(vector<int> &nums){
      int start= 0, end= nums.size()-1, n= nums.size(), mid, next, prev;
      
      // incase the entire array is sorted
      if(nums[start]<=nums[end]) return 0;
      
      while(start<=end){
        // calculate mid, prev, next
        mid= start + (end-start)/2;
        prev= (mid+n-1)%n;
        next= (mid+1)%n;
        
        // if mid is the minimum value
        if(nums[mid]<nums[prev] && nums[mid]<nums[next]) return mid;
        
        // if the mid lies in between a sorted portion, check left
        if(nums[mid]<nums[end]) end= mid-1;
        else start= mid+1;
      }
      
      return -1;
    }
  
    int binary__search(vector<int> &nums, int start, int end, int ele){
      int mid;
      
      while(start<=end){
        mid= start + (end-start)/2;
        
        if(nums[mid]==ele) return mid;
        
        else if(nums[mid]<ele) start= mid+1;
        else end= mid-1;
      }
      
      return -1;
    }

    int search(vector<int>& nums, int target) {
        int pos= findMinIndex(nums);
      
        if(pos==0) return binary__search(nums, 0, nums.size()-1, target);
        
        if(binary__search(nums, 0, pos-1, target)!=-1) return binary__search(nums, 0, pos-1, target);
        return binary__search(nums, pos, nums.size()-1, target);
    }
};