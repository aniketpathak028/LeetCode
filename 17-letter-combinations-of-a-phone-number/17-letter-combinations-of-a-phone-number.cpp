class Solution {
public:
    void findCombination(int i, string &digit, string comb, map<char,string> &mp, vector<string> &ans){
      // base-condition
      if(i==digit.size() && comb.size()>0){
        ans.push_back(comb);
        return;
      }
      
      string str= mp[digit[i]];
      for(int j=0; j<str.size(); ++j){
        // add this char to the string
        comb+= str[j];
        findCombination(i+1, digit, comb, mp, ans); // once character is chosen find for next index
        // remove this char and find for other char
        comb.pop_back();
      }
    }
  
    vector<string> letterCombinations(string digits) {
        map<char,string> mp;
        // mapping digits with characters
        mp['2']= "abc";
        mp['3']= "def";
        mp['4']= "ghi";
        mp['5']= "jkl";
        mp['6']= "mno";
        mp['7']= "pqrs";
        mp['8']= "tuv";
        mp['9']= "wxyz";
      
        vector<string> ans;
      
        findCombination(0, digits, "", mp, ans);
        return ans;
    }
};