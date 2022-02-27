// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
bool isSubsetSum(int N, int arr[], int sum)
{
    vector<vector<bool>> dp(N, vector<bool>(sum + 1, false));
    // base case intialization
    for (int i = 0; i < N; i++)
        dp[i][0] = true;

    dp[0][arr[0]] = true;

    for (int i = 1; i < N; i++){
        for (int j = 0; j <=sum; j++){
            bool not_pick = dp[i - 1][j];
            bool pick = false;
            if (arr[i] <= j)
                pick = dp[i - 1][j - arr[i]];

            dp[i][j] = pick || not_pick;
        }
    }

    return dp[N - 1][sum];
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