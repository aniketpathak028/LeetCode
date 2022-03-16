// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
   vector<int> SSL(long long arr[], int n)
    {
        vector<int> ans;
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (st.empty())
                ans.push_back(i - 0 + 1);
            else if (arr[st.top()] < arr[i])
                ans.push_back(i - st.top());
            else if (arr[st.top()] >= arr[i])
            {
                while (!st.empty() && arr[st.top()] >= arr[i])
                    st.pop();
                if (st.empty())
                    ans.push_back(i - 0 + 1);
                else
                    ans.push_back(i - st.top());
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> SSR(long long arr[], int n)
    {
        vector<int> ans;
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            if (st.empty())
                ans.push_back(n - i);
            else if (arr[st.top()] < arr[i])
                ans.push_back(st.top() - i);
            else if (arr[st.top()] >= arr[i])
            {
                while (!st.empty() && arr[st.top()] >= arr[i])
                    st.pop();
                if (st.empty())
                    ans.push_back(n - i);
                else
                    ans.push_back(st.top() - i);
            }
            st.push(i);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    long long getMaxArea(long long arr[], int n)
    {
        vector<int> ssl, ssr;
        ssl = SSL(arr, n);
        ssr = SSR(arr, n);
        long long maxi=INT_MIN;
        for(int i=0; i<n; i++) maxi= max(maxi, (ssr[i]+ssl[i]-1)*arr[i]);
        return maxi;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends