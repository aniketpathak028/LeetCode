class Solution {
public:
    int lcs(string s1, string s2){
      int n= s1.size(), m= s2.size();
      vector<int> prev(m+1), curr(m+1);
      // base-case
      for(int j=0; j<=m; ++j) prev[j]= 0;
      // tabulation
      for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
          if(s1[i-1]==s2[j-1]) curr[j]= 1+prev[j-1];
          else curr[j]= max(curr[j-1], prev[j]);
        }
        prev= curr;
      }
      
      return prev[m];
    }
  
    int minDistance(string word1, string word2) {
        int n= word1.size(), m= word2.size();
        int len= lcs(word1, word2);
        return n+m-(2*len);
    }
};