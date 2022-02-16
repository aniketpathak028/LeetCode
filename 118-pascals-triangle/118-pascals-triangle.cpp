class Solution {
public:
    void p(int i, vector<vector<int>> &ans, int n){
        if(i==n) return;
        if(i==0) {
           vector<int> row; 
           row.push_back(1);
           ans.push_back(row);
           return p(1, ans, n);
        }
        if(i==1) {
            vector<int> row; 
            row.push_back(1);
            row.push_back(1);
            ans.push_back(row);
            return p(2, ans, n);
        }
        
        vector<int> row; 
        row.push_back(1);
        
        auto prev = ans[ans.size()-1];
        
        for(int j=0; j<prev.size()-1; j++){
            row.push_back(prev[j]+prev[j+1]);
        }
        
        row.push_back(1);
        
        ans.push_back(row);
        
        p(i+1, ans, n);
        
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        p(0, ans, numRows);
        return ans;
    }
};