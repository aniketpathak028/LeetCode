class Word{
  public:
  string word;
  int count;
  
  Word(string word, int count) : word(word), count(count) {};
};

bool operator<(const Word& w1, const Word& w2){
	return w1.count==w2.count ? w1.word<w2.word : w1.count>w2.count;
}

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        priority_queue<Word> min_heap;
        for(auto &word: words) mp[word]++;
        for(auto &it: mp){
          min_heap.push(Word(it.first, it.second));
          if(min_heap.size()>k) min_heap.pop();
        }
        vector<string> ans;
        while(!min_heap.empty()){ 
          ans.push_back(min_heap.top().word);
          min_heap.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};