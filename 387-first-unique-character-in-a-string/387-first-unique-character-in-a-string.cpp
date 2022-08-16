class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mpp;
        vector<int> words(26, -1);
        for(int i=0; i<s.size(); ++i){
            if(words[s[i]-'a']==-1) words[s[i]-'a']= i;
            mpp[s[i]]++;
        }
        
        for(int i=0; i<s.size(); ++i){
            if(mpp[s[i]]==1) return words[s[i]-'a'];
        }
        
        return -1;
    }
};