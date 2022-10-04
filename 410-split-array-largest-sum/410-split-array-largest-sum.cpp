class Solution {
public:
    // function to determine if the partition is valid or not
    bool isValid(vector<int> &nums, int m, int maxi){
        int count= 1, sum= 0;
        for(auto &num: nums){
            sum+= num;
            if(sum>maxi){
                count++;
                sum= num;
            }
            if(count>m) return false;
        }
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
        if(nums.size()<m) return -1;
        int maxi= INT_MIN, sum= 0;
        // find sum of all elements in the array and the maximum element
        for(auto &num: nums){
            sum+= num;
            maxi= max(maxi, num);
        }
        // apply binary-search on answer
        int start= maxi, end= sum;
        int mid, res;
        while(start<=end){
            mid= start+(end-start)/2;
            if(isValid(nums, m, mid)){
                res= mid;
                end= mid-1;
            }else start= mid+1;
        }
        return res;
    }
};