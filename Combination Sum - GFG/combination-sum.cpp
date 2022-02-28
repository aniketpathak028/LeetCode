// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    void solve(int i, vector<int> &A, int sum, vector<int> com, vector<vector<int>> &ans){
        if(sum<0 | i==A.size()) return;
        if(sum==0){
            ans.push_back(com);
            return;
        }
        
        for(int j=i; j<A.size(); j++){
            if(A[j]==A[j-1]) continue;
            else{
                com.push_back(A[j]);
                if(A[j]<=sum) solve(j, A, sum-A[j], com, ans);
                com.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int> &A, int B) {
        vector<vector<int>> ans;
        sort(A.begin(), A.end());
        vector<int> com;
        solve(0, A, B, com, ans);
        return ans;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends