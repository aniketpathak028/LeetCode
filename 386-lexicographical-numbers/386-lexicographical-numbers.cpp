struct Node{
  Node* links[10];
  bool flag;
  
  bool containsKey(int dig){
    return links[dig]!=NULL;
  }
  
  void createRef(int dig){
    links[dig]= new Node();
  }
  
  Node* getNextNode(int dig){
    return links[dig];
  }
};

class Trie{
  public:
    Node* root;
  
    Trie(){
      root= new Node();
    }
  
    void insert(int num){
      string str= to_string(num);
      Node* node= root;
      for(int i=0; i<str.size(); ++i){
        int dig= str[i]-'0';
        if(!node->containsKey(dig)) node->createRef(dig);
        node= node->getNextNode(dig);
      }
      node->flag= true;
    }
  
    void dfs(Node* node, int num, vector<int> &ans){
      // if a number ends
      if(node->flag) ans.push_back(num);
      
      for(int i=0; i<10; ++i){
        if(node->containsKey(i)){
          dfs(node->getNextNode(i), num*10+i, ans);
        }
      }
    }
};

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        Trie trie;
        vector<int> ans;
        for(int i=1; i<=n; ++i) trie.insert(i);
        trie.dfs(trie.root, 0, ans);
        return ans;
    }
};