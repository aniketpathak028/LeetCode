// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    int longestSubsequence(int n, int a[])
    {
       int dp[n]={-1};
       dp[0]=1;
       for(int i=1; i<n; i++){
           int ans=1;
           for(int j=0; j<i; j++){
               if(a[j]<a[i]) ans= max(ans, 1+dp[j]);
           }
           dp[i]= ans;
       }
       int maxi=INT_MIN;
       for(int i=0; i<n; i++) maxi=max(maxi, dp[i]);
       return maxi;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends