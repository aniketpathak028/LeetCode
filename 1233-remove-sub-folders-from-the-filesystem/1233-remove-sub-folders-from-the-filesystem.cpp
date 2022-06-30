struct Node{
  Node* links[27];
  bool flag;
  
  bool containsKey(char ch){
    return (links[ch-'a']!=NULL);
  }
  
  Node* getNextNode(char ch){
    return links[ch-'a'];
  }
  
  void createRef(char ch){
    links[ch-'a']= new Node();
  }
};

class Trie{
  private:
    Node* root;
  public:
    Trie(){
      root= new Node();
    }
  
    void insert(string word){
      Node* node= root;
      for(int i=0; i<word.size(); ++i){
        if(!node->containsKey(word[i])) node->createRef(word[i]);
        node= node->getNextNode(word[i]);
      }
      node->flag= true;
    }
  
    bool search(string word){
      Node* node= root;
      for(int i=0; i<word.size(); ++i){
        if(!node->containsKey(word[i])) return false;
        node= node->getNextNode(word[i]);
      }
      return node->flag;
    }
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        sort(folder.begin(), folder.end());
        Trie trie;
        
        // replace '/' with '['
        for(string &f: folder)
          replace(f.begin(), f.end(), '/', '{');
        
        trie.insert(folder[0]);
        ans.push_back(folder[0]);
      
        for(int i=1; i<folder.size(); ++i){
           string curr= folder[i];
           int index= 0;
           string str= "";
           bool exists= false;
           while(index<curr.size()){
             if(curr[index]=='{'){
               if(trie.search(str)){
                  exists= true;
                  break;
               }
             } 
             str+= curr[index];
             index++;
           }
          if(exists) continue;
          ans.push_back(folder[i]);
          trie.insert(folder[i]);
        }
      
      for(string &f: ans)
          replace(f.begin(), f.end(), '{', '/');
      
      return ans;
    }
};