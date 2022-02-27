// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
   bool solve(int i, int target, int arr[], vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (i == 0)
        return arr[i] == target;

    if(dp[i][target]!=-1)
        return dp[i][target];

    bool not_pick = solve(i - 1, target, arr, dp);
    bool pick = false;
    if (arr[i] <= target)
        pick = solve(i - 1, target - arr[i], arr, dp);

    return dp[i][target] = pick || not_pick;
}
bool isSubsetSum(int N, int arr[], int sum)
{
    vector<vector<int>> dp(N, vector<int>(sum + 1, -1));
    return solve(N - 1, sum, arr, dp);
}
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends