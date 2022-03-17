// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
        vector<int> SSL(int arr[], int n)
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
    
        vector<int> SSR(int arr[], int n)
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
    
        int maxHist(int a[], int n)
        {
            auto ssl = SSL(a, n);
            auto ssr = SSR(a, n);
            int maxi = INT_MIN;
            for (int i = 0; i < n; i++)
                maxi = max(maxi, a[i] * (ssr[i] + ssl[i] - 1));
            return maxi;
        }
    
        int maxArea(int M[MAX][MAX], int n, int m) {
            for (int i = 1; i < n; i++)
                for (int j = 0; j < m; j++)
                    if (M[i][j] == 1) M[i][j] += M[i-1][j];
                    
            int maxi = INT_MIN;
            for (int i = 0; i < n; i++)
                maxi = max(maxi, maxHist(M[i], m));
            return maxi;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends