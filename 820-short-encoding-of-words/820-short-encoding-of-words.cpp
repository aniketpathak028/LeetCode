struct Node{
  Node* links[26];
  bool flag;
  
  bool containsKey(char ch){
    return links[ch-'a']!=NULL;
  }
  
  void createRef(char ch){
    links[ch-'a']= new Node();
  }
  
  Node* getNextRef(char ch){
    return links[ch-'a'];
  }
};

class Trie{
  Node* root;
public:
  Trie(){
    root= new Node();
  }
  
  void insert(string word){
    Node* node= root;
    for(int i=0; i<word.size(); ++i){
      if(!node->containsKey(word[i])) node->createRef(word[i]);
      node= node->getNextRef(word[i]);
    }
    node->flag= true;
  }
  
  bool endsWith(string suffix){
    Node* node= root;
    for(int i=0; i<suffix.size(); ++i){
      if(!node->containsKey(suffix[i])) return false;
      node= node->getNextRef(suffix[i]);
    }
    return node->flag;
  }
};

class Solution {
public:
    static bool cmp(string s1, string s2){
      return s1.size()>s2.size();
    }
      
    int minimumLengthEncoding(vector<string>& words) {
        Trie *obj= new Trie();
        int len= 0;
        sort(words.begin(), words.end(), cmp);
        for(auto &word: words){
          if(!obj->endsWith(word)){
            for(int i=0; i<word.size(); ++i){
              string sffx= word.substr(i);
              obj->insert(sffx);
            }
            len+= word.size()+1;
          }
        }
      return len;
    }
};