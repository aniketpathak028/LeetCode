// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    void solve(int i, string s, string perm, vector<string> &ans, vector<int> &v){
	        if(i==s.length()){
	            ans.push_back(perm);
	            return;
	        }
	        
	        for(int j=0; j<s.length(); j++){
	            if(v[j]==1){
	                v[j]=0;
	                solve(i+1, s, perm+s[j], ans, v);
	                v[j]=1;	            
	            }
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    vector<string> ans;
		    vector<int> v(S.length(), 1);
		    solve(0, S, "", ans, v);
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends