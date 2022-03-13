// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
    int mod= 1e9+7;
	int FindWays(int n, int m, vector<vector<int>>blocked_cells){
	   map<pair<int, int>, bool> mp;
	   vector<vector<int>> dp(n, vector<int>(m, 0));
	   for(auto i: blocked_cells) mp[{i[0]-1, i[1]-1}]=1;
	   for(int i=0; i<n; i++){
	       for(int j=0; j<m; j++){
	           if(mp[{i, j}]==1) {
	               dp[i][j]=0;
	           }
	           else if(i==0 && j==0){
	               dp[i][j]=1; // base-case
	           }
	           else{
	               if(i>0) dp[i][j] += dp[i-1][j];
	               if(j>0) dp[i][j] += dp[i][j-1];
	           }
	       }
	   }
	   return dp[n-1][m-1]%mod;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>>blocked_cells;
		for(int i = 0; i < k; i++){
			int x, y;
			cin >> x >> y;
			blocked_cells.push_back({x, y});
		}
		Solution obj;
		int ans = obj.FindWays(n, m, blocked_cells);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends