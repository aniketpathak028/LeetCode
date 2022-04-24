class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        
        string word= "";
      
        for(int i=0; i<s.size(); ++i){
          if(i>0 && (s[i]==' ' && s[i-1]!=' ')){
            words.push_back(word);
            word= "";
          }
          else if(s[i]!=' ') word+= s[i];
        }
      
        if(s[s.size()-1]!=' ') words.push_back(word);
      
        reverse(words.begin(), words.end());
      
        string ans= "";
        for(int i=0; i<words.size(); ++i){
          if(i==words.size()-1){
            ans+= words[i];
            break;
          }
          ans+= words[i] + ' ';
        }
      return ans;
    }
};