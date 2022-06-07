// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    void execution(vector<int> &circle, int i, int k){
        if(circle.size()==1) return;
        int index= (i+k)%circle.size();
        circle.erase(circle.begin()+index);
        execution(circle, index, k);
    }
    
    int safePos(int n, int k) {
        vector<int> circle(n);
        iota(circle.begin(), circle.end(), 1);
        execution(circle, 0, k-1);
        return circle[0];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        
        cin>>n>>k;

        Solution ob;
        cout << ob.safePos(n,k) << endl;
    }
    return 0;
}  // } Driver Code Ends