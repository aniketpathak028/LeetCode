class Solution {
public:
    double multiply(double num, long long n){
      // base-case if n = 0 or 1
      if(n==0) return 1;
      if(n==1) return num;
      
      double half= multiply(num, n/2);
      if(n&1) return half*half*num;
      else return half*half;
    }
  
    double myPow(double x, int n) {
        return n>=0 ? multiply(x, n) : (1/multiply(x, n));
    }
};