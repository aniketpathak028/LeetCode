struct Node {
  Node* links[26];
  bool flag;
  
  bool containsKey(char ch) {
    return links[ch-'a']!=NULL;
  }
  
  void createRef(char ch){
    links[ch-'a']= new Node();
  }
  
  Node* getNextRef(char ch){
    return links[ch-'a'];
  }
};

class Trie {
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
  
  vector<string> startsWith(string prefix){
    Node* node= root;
    vector<string> ans;
    for(int i=0; i<prefix.size(); ++i){
      if(!node->containsKey(prefix[i])) return ans;
      node= node->getNextRef(prefix[i]);
    }
    dfs(prefix, node, ans);
    return ans;
  }
  
  void dfs(string prefix, Node* node, vector<string> &ans){
    if(ans.size()==3 || !node) return;
    
    if(node->flag) ans.push_back(prefix);
    
    for(char ch='a'; ch<='z'; ch++){
      if(node->links[ch-'a']){
        dfs(prefix+ch, node->links[ch-'a'], ans);
      }
    }
  }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie *obj= new Trie();
        vector<vector<string>> ans;
        for(auto &prod: products) obj->insert(prod);
        string toSearch= "";
        for(int i=0; i<searchWord.size(); ++i){
          toSearch+= searchWord[i];
          ans.push_back(obj->startsWith(toSearch));
        }
      return ans;
    }
};