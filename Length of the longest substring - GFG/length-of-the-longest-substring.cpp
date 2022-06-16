// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string S){
       vector<int> mpp(256, -1);
       int left= 0, right= 0, len= 0;
       while(right<S.size()){
           if(mpp[S[right]]>=0 && mpp[S[right]]>=left) left= mpp[S[right]]+1;
           else mpp[S[right]]= right++;
           len= max(len, right-left);
       }
       return len;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}  // } Driver Code Ends