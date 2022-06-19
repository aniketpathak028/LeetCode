struct Node{
  Node* links[26];
  bool flag;
  
  bool containsKey(char ch){
    return links[ch-'a']!=NULL;
  }
  
  Node* getNextRef(char ch){
    return links[ch-'a'];
  }
  
  void createRef(char ch){
    links[ch-'a']= new Node();
  }
};

class WordDictionary {
  Node* root;
public:
    WordDictionary() {
        root= new Node();
    }
    
    void addWord(string word) {
        Node* node= root;
        for(int i=0; i<word.size(); ++i){
          if(!node->containsKey(word[i])) node->createRef(word[i]);
          node= node->getNextRef(word[i]);
        }
        node->flag= true;
    }
  
    bool dfs(int i, string &word, Node* node){
      if(node==NULL) return false;
      if(i==word.size()) return node->flag;
      
      char ch= word[i];
      if(ch=='.'){
        for(char c='a'; c<='z'; ++c){
          if(dfs(i+1, word, node->getNextRef(c))) return true;
        }
        return false;
      }else{
        if(!node->containsKey(ch)) return false;
        return dfs(i+1, word, node->getNextRef(ch));
      }
    }
    
    bool search(string word) {
      Node* node= root;
      if(word.find('.')==string::npos){
        for(int i=0; i<word.size(); ++i){
          if(!node->containsKey(word[i])) return false;
          node= node->getNextRef(word[i]);
        }
        return node->flag;
      }
      return dfs(0, word, node);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */