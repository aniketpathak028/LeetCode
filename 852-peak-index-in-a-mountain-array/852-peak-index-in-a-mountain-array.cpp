class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s= 0, e= arr.size()-1, mid, n= arr.size();
        
        while(s<=e){
            mid= s+(e-s)/2;
            if(mid>0 && mid<n-1){
                if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
                else if(arr[mid+1]>arr[mid]) s= mid+1;
                else e= mid-1;
            }else if(mid==0) return mid+1;
            else return n-2;
        }
        
        return -1;
    }
};