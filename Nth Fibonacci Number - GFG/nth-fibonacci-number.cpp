// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
long long int mod = 1e9+7;
class Solution {
  public:
    long long int solve(long long int n, vector<long long int> &dp){
        if(n<=1) return n;
        
        if(dp[n]!=-1) return dp[n];
        
        return dp[n]= (solve(n-1, dp)+solve(n-2, dp))%mod;
    }
    long long int nthFibonacci(long long int n){
        vector<long long int> dp(n+1, -1);
        return solve(n, dp);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}
  // } Driver Code Ends