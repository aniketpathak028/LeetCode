// { Driver Code Starts

#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	vector<int> first_and_last(int arr[], int n, int num){
	    vector<int> ans;
	    int first= -1, last= -1;
	    // first occurence
	    int start= 0, end= n-1, mid;
	    while(start<=end){
	        mid= start+(end-start)/2;
	        if(arr[mid]==num){
	            end= mid-1;
	            first= mid;
	        }
	        else if(arr[mid]>num) end= mid-1;
	        else start= mid+1;
	    }
	    ans.push_back(first);
	    // last occurence
	    start= 0, end= n-1;
	    while(start<=end){
	        mid= start+(end-start)/2;
	        if(arr[mid]==num){
	            start= mid+1;
	            last= mid;
	        }
	        else if(arr[mid]>num) end= mid-1;
	        else start= mid+1;
	    }
	    ans.push_back(last);
	    
	    return ans;
	}
	
	int count(int arr[], int n, int x) {
	    auto ans= first_and_last(arr, n, x);
	    if(ans[0]==-1 && ans[1]==-1) return 0;
	    else return ans[1]-ans[0]+1;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends