class Node {
public:
  Node* links[26];
  bool flag;

  bool containsKey(char ch){
    return links[ch-'a']!=NULL;
  }
  
  Node* getNextNode(char ch){
    return links[ch-'a'];
  }
  
  void createRef(char ch){
    links[ch-'a']= new Node();
  }
};

class Trie {
  Node* root;
  
public:
    Trie() {
        root= new Node();
    }
    
    void insert(string word) {
        Node* node= root;
        for(int i=0; i<word.size(); ++i){
          if(!node->containsKey(word[i])) node->createRef(word[i]);
          node= node->getNextNode(word[i]);
        }
        node->flag= true;
    }
    
    bool search(string word) {
        Node* node= root;
        for(int i=0; i<word.size(); ++i){
          if(!node->containsKey(word[i])) return false;
          node= node->getNextNode(word[i]);
        }
        return node->flag;
    }
    
    bool startsWith(string prefix) {
        Node* node= root;
        for(int i=0; i<prefix.size(); ++i){
          if(!node->containsKey(prefix[i])) return false;
          node= node->getNextNode(prefix[i]);
        }
      return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */