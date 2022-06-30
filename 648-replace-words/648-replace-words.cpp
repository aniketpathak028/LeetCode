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
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans="";
        Trie* obj= new Trie();
        // insert dictionary into trie
        for(string &word: dictionary) obj->insert(word);
      
        vector<string> sent;
        string str= "";
        int index= 0;
        while(index<sentence.size()){
          if(sentence[index]==' '){
            sent.push_back(str);
            str= "";
            index++;
          }else{
            str+= sentence[index];
            index++;
          }
        }
        sent.push_back(str);
        
        for(string &word: sent){
          string prefix= "";
          for(int i=0; i<word.size(); ++i){
            prefix+= word[i];
            if(obj->search(prefix)) break;
          }
          ans+= prefix;
          ans+= " ";
        }
      
      ans.pop_back();
      
      return ans;
    }
};