class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        long long c1, c2, ans;
        c1=c2=ans=0;
        for(int i=0; i<text.size(); i++){
            if(text[i]==pattern[1]) {
                ans+=c1;
                c2++;
            }
            if(text[i]==pattern[0]) c1++;
        }
        return ans+max(c1,c2);
    }
};