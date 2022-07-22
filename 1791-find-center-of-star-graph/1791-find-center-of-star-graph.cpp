class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
       unordered_map<int,int> mpp;
       for(auto &it: edges){
         mpp[it[0]]++;
         mpp[it[1]]++;
       }
       int center, maxi= 0;
      
       for(auto &it: mpp){
         if(it.second>maxi){
           center= it.first;
           maxi= it.second;
         }
       }
      return center;
    }
};