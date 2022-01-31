// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void checkSubsetSum(int i, vector<int> &arr, int &curr_sum, vector<int> &ans){
        // base condition
        if(i==arr.size()){
            ans.push_back(curr_sum);
            return;
        }
        
        // case where we include the index
        curr_sum+= arr[i];
        checkSubsetSum(i+1, arr, curr_sum, ans);
        
        // case where we don't include the current index
        curr_sum-=arr[i];
        checkSubsetSum(i+1, arr, curr_sum, ans);
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
       vector<int> ans;
       int curr_sum = 0;
       checkSubsetSum(0, arr, curr_sum, ans);
       return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends