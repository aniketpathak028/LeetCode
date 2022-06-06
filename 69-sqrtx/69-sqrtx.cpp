class Solution {
public:
    int mySqrt(int x) {
        long long lo= 1, hi= x;
        long long mid;
        while(hi-lo>1){
          mid= (hi+lo)/2;
          if(mid*mid>x)
            hi= mid-1;
          else
            lo= mid;
        }
        if(hi*hi<=x) return hi;
        else return lo;
    }
};