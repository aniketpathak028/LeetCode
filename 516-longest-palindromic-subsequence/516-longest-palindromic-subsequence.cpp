class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string text1 = s;
        reverse(s.begin(), s.end());
        string text2 = s;
        vector<int> curr(text2.size()+1, 0), prev(text2.size()+1, 0);

        for(int i=1; i<=text1.size(); i++){
            for(int j=1; j<=text2.size(); j++){
                if(text1[i-1]==text2[j-1]) curr[j]= 1+prev[j-1];
                else curr[j]= max(prev[j], curr[j-1]);
            }
            prev= curr;
        }
        
        return prev[text2.size()];
    }
};