struct Node{
  Node* links[26];
  bool flag;
  
  bool containsKey(char ch){
    return links[ch-'a']!=NULL;
  }
  
  void createRef(char ch){
    links[ch-'a']= new Node();
  }
  
  Node* getNextNode(char ch){
    return links[ch-'a'];
  }
};

class MagicDictionary {
private:
  Node* root;
public:
    MagicDictionary() {
        root= new Node();
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto &word: dictionary){
          Node* node= root;
          for(int i=0; i<word.size(); ++i){
            if(!node->containsKey(word[i])) node->createRef(word[i]);
            node= node->getNextNode(word[i]);
          }
          node->flag= true;
        }
    }
  
    bool isPresent(string word){
      Node* node= root;
      for(int i=0; i<word.size(); ++i){
        if(!node->containsKey(word[i])) return false;
        node= node->getNextNode(word[i]);
      }
      return node->flag;
    }
  
    bool search(string searchWord) {
      string word= searchWord;
      for(int i=0; i<word.size(); ++i){
        for(int j=0; j<26; ++j){
          if('a'+j!=word[i]){
            word[i]= 'a' + j;
            if(isPresent(word)) return true;
            word= searchWord;
          }
        }
      }
      return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */