struct Node {
  Node* links[27];
  int rank;
  
  bool containsKey(char ch) {return links[ch-'a']!=NULL;}
  
  void createRef(char ch) {links[ch-'a']= new Node();}
  
  Node* getNextRef(char ch) {return links[ch-'a'];}
  
  int getRank() {return rank;}
  
  void setRank(int r) {rank= r;} 
};

class WordFilter {
public:
    Node* root;
  
    WordFilter(vector<string>& words) {
        root= new Node();
        
        for(int rank=0; rank<words.size(); ++rank){
              string word= '{' + words[rank];
              insertWord(word, rank);
              for(int i=1; i<word.size(); ++i){
                string pref= word.substr(i);
                insertWord(pref+word, rank);
              }
        }
    }
  
    void insertWord(string word, int rank){
      Node* node= root;
      for(int i=0; i<word.size(); ++i){
        if(!node->containsKey(word[i])) node->createRef(word[i]);
        node->setRank(rank);
        node= node->getNextRef(word[i]);
      }
      node->setRank(rank);
    }
    
    int f(string prefix, string suffix) {
        string word= suffix + '{' + prefix;
        Node* node= root;
        for(int i=0; i<word.size(); ++i){
          if(!node->containsKey(word[i])) return -1;
          node= node->getNextRef(word[i]);
        }
      return node->getRank();
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */