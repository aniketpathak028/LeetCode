class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       vector<int> mp(256, -1); // map to store the last position of a character
       int left= 0, right= 0, len= 0, n= s.size(); // set right and left pointer as 0 and n as size of string
       while(right<n){
         if(mp[s[right]]!=-1 && mp[s[right]]>=left) left= mp[s[right]]+1;
         mp[s[right]]= right;
         len= max(len, right-left+1);
         right++;
       }
      return len;
    }
};