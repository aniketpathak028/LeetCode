class Solution {
public:
    // optimized approach using stack
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int s2= INT_MIN; // as we need to find nums[i] smaller than s2
        
        // traversing the array from the end
        for(int i=nums.size()-1; i>=0; --i){
          int s3= nums[i];
          if(s3<s2) return true;
          while(!st.empty() && st.top()<s3){
            s2= st.top();
            st.pop();
          }
          st.push(s3);
        }
      return false;
    }
};