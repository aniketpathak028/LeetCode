// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
   
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        vector<vector<int>> dp(vector<vector<int>>(N, vector<int>(N, 0)));
        
        // base-case
        for(int i=0; i<N; i++){
            dp[N-1][i] = Matrix[N-1][i];
        }
        
        for(int i=N-2; i>=0; i--){
            for(int j=0; j<N; j++){
                int maxi = 0;
        
                for(int dj=-1; dj<=1; dj++){
                    if(j+dj>=0 && j+dj<N){
                        int val = dp[i+1][j+dj] + Matrix[i][j];
                        maxi = max(maxi, val);
                    }
                }
                
                dp[i][j] = maxi;
            }
        }
        
        int maxi = 0;
        for(int i=0; i<N; i++){
            maxi = max(maxi, dp[0][i]);
        }
       
        return maxi;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends