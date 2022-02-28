// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}// } Driver Code Ends



//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.

long long numOfWays(int N, int M)
{
    long long ans=0;
    long long count=0;
    long long mod=1e9+7;
   
   for(int i=0;i<N;i++)
   {   
       
       for(int j=0;j<M;j++)
       {   
           count=0;
           
           if(i+2<N and j+1<M)
           count++;
           
           if(i+2<N and j-1>=0)
           count++;
           
           if(i-2>=0 and j+1<M)
           count++;
           
           if(i-2>=0 and j-1>=0)
           count++;
           
           if(i+1<N and j+2<M)
           count++;
           
           if(i+1<N and j-2>=0)
           count++;
           
           if(i-1>=0 and j+2<M)
           count++;
           
           if(i-1>=0 and j-2>=0)
           count++;
           
           count++;
           
           ans=ans%mod+(((N%mod)*(M%mod))%mod-count)%mod;
           
       }
       
   }
   
   return ans;
}