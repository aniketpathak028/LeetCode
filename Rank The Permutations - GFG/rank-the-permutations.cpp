// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    long long fac(int n){
        return (n <= 1) ? 1 : n * fac(n - 1);
    }
    long long countSmallRight(string s, int l, int h){
        long long cnt= 0;
        for(long long i=l+1; i<=h; i++) cnt += s[i]<s[l] ? 1 : 0;
        return cnt;
    }
    long long findRank(string str) {
        long long len = str.length();
        long long fact = fac(len);
        long long rank= 1;
        for(long long i=0; i<len; i++){
            fact /= len-i;
            long long cr = countSmallRight(str, i, len-1);
            rank += cr*fact;
        }
        return rank;
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        Solution obj;
        long long ans = obj.findRank(s);
        cout<<ans<<endl;
    }
}  // } Driver Code Ends