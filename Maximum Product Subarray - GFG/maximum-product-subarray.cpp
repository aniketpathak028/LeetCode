// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    if(n==0) return -1;
	    
	    long long int minProd = arr[0];
	    long long int maxProd = arr[0];
	    long long int ans = arr[0];
	    
	    for(int i=1; i<n; i++){
	        long long int curr = arr[i];
	        long long int choice1 = minProd * arr[i];
	        long long int choice2 = maxProd * arr[i];
	        minProd = min(curr, min(choice1, choice2));
	        maxProd = max(curr, max(choice1, choice2));
	        ans = max(ans, maxProd);
	    }
	    
	    return ans;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends