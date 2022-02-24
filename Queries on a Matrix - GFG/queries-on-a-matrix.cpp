// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> solveQueries(int n, vector<vector<int>> Queries) {
        vector<vector<int>> grid(n, vector<int>(n, 0));
        
        for(int i=0; i<Queries.size(); i++){
            int a = Queries[i][0];
            int b = Queries[i][1];
            int c = Queries[i][2];
            int d = Queries[i][3];
            
            for(int i1=a; i1<=c; i1++){
                 for(int j1=b; j1<=d; j1++){
                    grid[i1][j1]++;
                }
            }
            
        }
        
        return grid;
            
        }
        
        
    };

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, q;
        cin >> n >> q;
        vector<vector<int>> Queries;
        for (int i = 0; i < q; i++) {
            vector<int> cur(4);
            for (int j = 0; j < 4; j++) cin >> cur[j];
            Queries.push_back(cur);
        }
        Solution obj;
        vector<vector<int>> ans = obj.solveQueries(n, Queries);
        for (auto i : ans) {
            for (auto j : i) cout << j << " ";
            cout << "\n";
        }
    }
    return 0;
}  // } Driver Code Ends