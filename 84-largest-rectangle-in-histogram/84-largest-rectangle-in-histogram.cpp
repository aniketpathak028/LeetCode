class Solution {
public:
    vector<int> SSL(vector<int> arr, int n)
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

    vector<int> SSR(vector<int> arr, int n)
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
    
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        vector<int> ssl, ssr;
        ssl = SSL(heights, n);
        ssr = SSR(heights, n);
        int maxi=INT_MIN;
        for(int i=0; i<n; i++) maxi= max(maxi, (ssr[i]+ssl[i]-1)*heights[i]);
        return maxi;
    }
};