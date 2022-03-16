// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        vector<long long> gl(n);
        vector<long long> gr(n);
        
        long long g = gl[0] = arr[0];
        for (long long i = 1; i<n; i++) {
            gl[i] = g;
            if(arr[i]>g)
                g = arr[i];
        }
        
        g = gr[n-1] = arr[n-1];
        for (long long i = n-2; i >=0 ; i--)
        {
            gr[i] = g;
            if (arr[i] > g)
                g = arr[i];
        }
        
        long long w = 0;
        for (long long i = 0; i < n; i++){
            w += min(gl[i], gr[i]) >= arr[i] ? min(gl[i], gr[i]) - arr[i] : 0;
        }
        
        return w;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends