// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int CountPS(char S[], int N);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        char S[N+1];
        cin>>S;
        cout<<CountPS(S,N)<<endl;
    }
    return 0;
}

// } Driver Code Ends


int CountPS(char S[], int N)
{
    int cnt= 0;
    vector<vector<bool>> dp(N, vector<bool>(N));
    for(int g=0; g<N; ++g){
        int i= 0, j= g;
        while(j<N){
         if(g==0) dp[i][j]= 1;
         else if(g==1) dp[i][j]= S[i]==S[j];
         else dp[i][j]= S[i]==S[j] && dp[i+1][j-1];
         if(dp[i][j] && j-i+1>=2) cnt++;
         i++; j++;
        }
    }
    return cnt;
}