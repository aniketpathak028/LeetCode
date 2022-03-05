class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
      
        for(int i=0;i<=n;i++){
            
            int cnt= 0;
            int n= i;
            while(n){
                cnt++;
                
                n= n&(n-1);
            }
            
            ans.push_back(cnt);
        }
        
        return ans;
    }
};