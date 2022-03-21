// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    int vis[501][501];
    void dfs(int i, int j, int n, int m, vector<vector<char>> &grid){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='0' || vis[i][j]==1) return;
        
        vis[i][j]=1;
        dfs(i-1, j, n, m, grid);
        dfs(i+1, j, n, m, grid);
        dfs(i, j+1, n, m, grid);
        dfs(i, j-1, n, m, grid);
        dfs(i+1, j+1, n, m, grid);
        dfs(i-1, j-1, n, m, grid);
        dfs(i+1, j-1, n, m, grid);
        dfs(i-1, j+1, n, m, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        int count= 0;
        memset(vis, 0, sizeof(vis));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(i, j, n, m, grid);
                    count++;
                }
            }
        }
        return count;  
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends