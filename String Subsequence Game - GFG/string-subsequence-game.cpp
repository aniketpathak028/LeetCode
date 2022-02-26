// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    set<string> allPossibleSubsequences(string S) {
        set<string> s;
        int n = S.length();
        for(int i=0; i<(1<<n); i++){
            string sub= "";
            for(int j=0; j<n; j++){
                if((1<<j) & i) sub+=S[j];
            }
            if((sub[0]=='a' || sub[0]=='e'||sub[0]=='i'||sub[0]=='o'||sub[0]=='u')&&(sub[sub.length()-1]!='a'&&sub[sub.length()-1]!='e'&&sub[sub.length()-1]!='i'&&sub[sub.length()-1]!='o'&&sub[sub.length()-1]!='u')) s.insert(sub);
        }
        return s;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        set<string> ans = ob.allPossibleSubsequences(S);
        if (ans.size() == 0)
            cout << -1 << endl;
        else {
            for (auto i : ans) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}
  // } Driver Code Ends