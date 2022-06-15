// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // finding lcs length
	    int n= x, m= y;
	    vector<int> prev(m+1), curr(m+1);
	    prev[0]= 0; // base-case
	    for(int i=1; i<=n; ++i){
	        for(int j=1; j<=m; ++j){
	            if(s1[i-1]==s2[j-1]) curr[j]= 1+prev[j-1];
	            else curr[j]= max(curr[j-1], prev[j]);
	        }
	       prev= curr;
	    }
	    return prev[m]; // length
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends