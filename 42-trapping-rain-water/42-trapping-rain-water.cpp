class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        vector<int> gl(n);
        vector<int> gr(n);

        int g = gl[0] = height[0];
        for (int i = 1; i < n; i++)
        {
            gl[i] = g;
            if (height[i] > g)
                g = height[i];
        }

        g = gr[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            gr[i] = g;
            if (height[i] > g)
                g = height[i];
        }

        int w = 0;
        for (int i = 0; i < n; i++){
            w += min(gl[i], gr[i]) > height[i] ? min(gl[i], gr[i]) - height[i] : 0;
        }
        
        return w;
    }
};