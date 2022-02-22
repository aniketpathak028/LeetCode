class Solution {
public:
    bool solve(vector<int> &arr, int i, map<int, int> &m){
        if(i<0 || i>arr.size()-1 || m[i]==1) return false;
        
        m[i] = 1;
        if(arr[i]==0) return true;

        
        bool l = solve(arr, i-arr[i], m);
        bool r = solve(arr, i+arr[i], m);
        
        return l||r;
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        map<int, int> m;
        if(n==1) return arr[0]==0 ? true : false;
        return solve(arr, start, m);
    }
};