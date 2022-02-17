class Solution {
public:
 
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> prev(n);
        for (int i = 0; i < n; i++){
            prev[i] = triangle[n - 1][i];
        }
        for (int i = n-2; i >= 0; i--)
        {
            vector<int> curr(i+1);
            for (int j = i; j >= 0; j--)
            {
                int d, dr;
                d = triangle[i][j] + prev[j];
                dr = triangle[i][j] + prev[j+1];

                curr[j] = min(d, dr);
            }
            prev = curr;
        }

        return prev[0];
    }
};