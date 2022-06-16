// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int lcs(string s1, string s2){
        int n= s1.size(), m= s2.size();
        vector<int> prev(m+1), curr(m+1);
        prev[0]= 0;
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                if(s1[i-1]==s2[j-1]) curr[j]= 1+prev[j-1];
                else curr[j]= max(curr[j-1], prev[j]);
            }
            prev= curr;
        }
        return prev[m];
    }
    
    int longestPalinSubseq(string A) {
        string rev= A;
        reverse(A.begin(), A.end());
        return lcs(A, rev);
    }
};

// { Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends