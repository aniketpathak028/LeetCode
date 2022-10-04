class Solution {
public:
    bool canDistribute(vector<int> quantities, int n, int k){
        int count= 0;
        for(int i=0; i<quantities.size(); ++i){
            if(quantities[i]%k==0) count+= quantities[i]/k;
            else count+= (quantities[i]/k) + 1;
            if(count>n) return false;
        }
        return true;
    }
    
    int minimizedMaximum(int n, vector<int>& quantities) {
        if(quantities.size()>n) return -1;
        // find maximum element and sum
        int maxi= INT_MIN;
        long sum= 0;
        for(auto &q: quantities){
            maxi= max(maxi, q);
            sum+= q;
        }
        int mini= sum/n;
        // apply binary-search on answer
        int start= mini, end= maxi;
        int mid, res;
        if(start==0) start++;
        while(start<=end){
            mid= start+(end-start)/2;
            if(canDistribute(quantities, n, mid)){
                res= mid;
                end= mid-1;
            }else start= mid+1;
        }
        return res;
    }
};