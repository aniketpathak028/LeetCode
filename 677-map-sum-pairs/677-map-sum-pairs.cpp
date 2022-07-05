struct Node{
  Node* links[26];
  int value;

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

class MapSum {
private:
  Node* root;
  
public:
    MapSum() {
        root= new Node();
    }
    
    void insert(string key, int val) {
        Node* node= root;
        for(int i=0; i<key.size(); ++i){
          if(!node->containsKey(key[i])) node->createRef(key[i]);
          node= node->getNextNode(key[i]);
        }
        node->value= val;
    }
  
    int dfs(Node* node){
      int sum= 0;
      
      if(node->value) sum+= node->value;
      
      for(int i=0; i<26; ++i){
        if(node->links[i]) sum+= dfs(node->links[i]);
      }
      
      return sum;
    }
    
    int sum(string prefix) {
       Node* node= root;
       for(int i=0; i<prefix.size(); ++i){
         if(!node->containsKey(prefix[i])) return 0;
         node= node->getNextNode(prefix[i]);
       }
      return dfs(node);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */