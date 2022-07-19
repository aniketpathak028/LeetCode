class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0; i<numRows; ++i){
          vector<int> row;
          row.push_back(1);
          if(i==0){
            ans.push_back(row);
            continue;
          }
          else if(i==1){
            row.push_back(1);
            ans.push_back(row);
            continue;
          }
          else{
            for(int j=0; j<ans[i-1].size()-1; ++j){
              row.push_back(ans[i-1][j]+ans[i-1][j+1]);
            }
            row.push_back(1);
            ans.push_back(row);
          }
        }
      return ans;
    }
};