class Solution {
public:
    int last(vector<int> &arr, int element){
      int start= 0, end= arr.size()-1, mid, res= -1;
      while(start<=end){
        mid= start + (end-start)/2;
        if(arr[mid]==element){
          res= mid;
          start= mid+1;
        }
        else if(element<arr[mid]) end= mid-1;
        else start= mid+1;
      }
      return res;
    }
  
    int first(vector<int> &arr, int element){
      int start= 0, end= arr.size()-1, mid, res= -1;
      while(start<=end){
        mid= start + (end-start)/2;
        if(arr[mid]==element){
          res= mid;
          end= mid-1;
        }
        else if(element<arr[mid]) end= mid-1;
        else start= mid+1;
      }
      return res;
    }
  
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(first(nums, target));
        ans.push_back(last(nums, target));
        return ans;
    }
};