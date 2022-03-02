// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0; i<N; i++) sum+=arr[i];
        if(sum&1) return false;
        sum= sum/2;
        vector<bool> curr(sum+1, false), prev(sum+1, false);
        prev[0]=curr[0]=1;
        if(arr[0]<=sum) prev[arr[0]]=1;
        for(int i=1; i<N; i++){
            for(int j=1; j<=sum; j++){
                bool not_take = prev[j];
                bool take = false;
                if(arr[i]<=j) take= prev[j-arr[i]];
                curr[j] = take | not_take;
            }
            prev= curr;
        }
        return prev[sum];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends