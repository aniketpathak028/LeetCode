// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    int n= M;
	    int amount= V;
        // intialize dp
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        // base-case
        for(int i=0; i<=amount; i++) dp[0][i] = i%coins[0]==0 ? i/coins[0] : 1e9;
        // tabulation
        for(int i=1; i<n; i++){
            for(int j=0; j<=amount; j++){
                int pick, notPick;
                pick=INT_MAX;
                notPick= dp[i-1][j];
                if(j>=coins[i]) pick= 1 + dp[i][j-coins[i]];
                dp[i][j]= min(pick, notPick);
            }
        }
        int ans = dp[n-1][amount];
        if(ans>=1e9) return -1;
        return ans;
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends