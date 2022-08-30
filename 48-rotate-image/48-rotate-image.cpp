class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> mat;
        for(int j=0; j<matrix[0].size(); ++j){
            vector<int> col;
            for(int i=0; i<matrix.size(); ++i){
                col.push_back(matrix[i][j]);
            }
            reverse(col.begin(), col.end());
            mat.push_back(col);
        }
        for(int i=0; i<matrix.size(); ++i) matrix[i]= mat[i];
    }
};