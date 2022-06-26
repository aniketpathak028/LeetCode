// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        long ans= INT_MIN, sum= 0;
        vector<long> prefix(N);
        for(int i=0; i<N; ++i){
            sum+= Arr[i];
            prefix[i]= sum;
        }
        for(int i=0, j=K-1; j<N; ++i, ++j){
            ans= max(ans, prefix[j]-prefix[i]+Arr[i]);
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
}   // } Driver Code Ends