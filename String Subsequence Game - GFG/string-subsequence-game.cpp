// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int isVowel(char ch)
    {
        return (0x208222 >> (ch & 0x1f)) & 1;
        // same as (2130466 >> (ch & 31)) & 1;
    }
    set<string> allPossibleSubsequences(string S) {
        set<string> s;
        int n = S.length();
        for(int i=0; i<(1<<n); i++){
            string sub= "";
            for(int j=0; j<n; j++){
                if((1<<j) & i) sub+=S[j];
            }
            if(isVowel(sub[0]) && !isVowel(sub[sub.length()-1])) s.insert(sub);
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