// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
    int solve(int arr[], int n, int sum){
        // initialize dp
        vector<vector<bool>> dp(n, vector<bool>(sum+1, false));
        // base-case initialization
        for(int i=0; i<n; i++) dp[i][0]= true;
        if(arr[0]<=sum) dp[0][arr[0]]= true;
        // tabulation
        for(int i=1; i<n; i++){
            for(int j=1; j<=sum; j++){
                bool not_pick = dp[i-1][j];
                bool pick = false;
                if(arr[i]<=j) pick = dp[i-1][j-arr[i]];
                
                dp[i][j]= pick | not_pick;
            }
        }
        
        int mini = INT_MAX;
        for(int i=0; i<=sum; i++) if(dp[n-1][i]) mini= min(mini, abs((sum-i)-i));
        
        return mini;
    }
	int minDifference(int arr[], int n)  { 
	    int tot_sum= 0;
	    for(int i=0; i<n; i++) tot_sum+=arr[i];
	    return solve(arr, n, tot_sum);
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends