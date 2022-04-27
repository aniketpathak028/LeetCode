class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int> odd, even;
        vector<int> idx;
        while(num){
          int dig= num%10;
          if(dig&1){
            idx.push_back(0);
            even.push(dig);
          } 
          else {
            idx.push_back(1);
            odd.push(dig);
          }
          num /= 10;
        }
        reverse(idx.begin(), idx.end());
        int ans= 0;
        for(int i=0; i<idx.size(); ++i){
          ans*= 10;
          if(idx[i]){
            ans+= odd.top();
            odd.pop();
          }else{
            ans+= even.top();
            even.pop();
          }
        }
      return ans;
    }
};