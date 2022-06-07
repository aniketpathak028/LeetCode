class Solution {
public:
    void insert(vector<int> &arr, int num, int index){
      int temp= num;
      for(int i= index; i<arr.size(); ++i){
        int curr_num= arr[i];
        arr[i]= temp;
        temp= curr_num;
      }    
    }
  
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i= 0, j= 0;
        while(i<n && j<m){
          if(nums2[i]<=nums1[j]){
            insert(nums1, nums2[i], j);
            i++;
            j++;
            m++;
          } 
          else{
            j++;
          }
        }
        while(i<n){
          nums1[j++]= nums2[i++];
        }
    }
};