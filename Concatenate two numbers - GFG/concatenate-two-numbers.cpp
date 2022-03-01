// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
        void prefix(int c,int X,long long &count,unordered_map <string,int> &umap)
   {
       string str=to_string(c),x=to_string(X);
       int n=str.length();
       if(x.substr(0,n)==str)
       {
           count+=umap[x.substr(n)];
           if(x.substr(0,n)==x.substr(n))
           count--;
       }
   }
   
   
   long long countPairs(int N, int X, vector<int> numbers){
     unordered_map <string,int> umap;
     long long count=0;
     for(auto c:numbers)
         umap[to_string(c)]++;
     for(auto c:numbers)
     {
         prefix(c,X,count,umap);
     }
     return count;
   }
}; 

// { Driver Code Starts.
int main() 
{ 
    int t;cin>>t;
    while(t--)
    {
        int N,X;
        cin>>N>>X;
        vector<int> numbers(N);
        for(int i=0;i<N;i++)
            cin>>numbers[i];
        Solution ob;
        long long ans = ob.countPairs(N, X, numbers);
        cout<<ans<<endl;
        
    }

    return 0; 
}  // } Driver Code Ends