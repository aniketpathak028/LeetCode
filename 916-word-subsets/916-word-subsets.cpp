class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        // find the max frequency of each char from all the words
        vector<int> freq(26);
        for(string &word: words2){
          vector<int> mpp(26);
          for(char &ch: word){
            mpp[ch-'a']++;
          }
          for(int i=0; i<26; ++i){
            freq[i]= max(freq[i], mpp[i]);
          }
        }
        
        vector<string> ans;
        for(auto &word: words1){
          bool isUniversal= true;
          unordered_map<char,int> mpp;
          for(auto &ch: word) mpp[ch]++;
          for(int i=0; i<26; ++i){
            if(freq[i]>mpp[i+'a']){
              isUniversal= 0;
              break;
            }
          }
          
          if(isUniversal) ans.push_back(word);
        }
      return ans;
    }
};