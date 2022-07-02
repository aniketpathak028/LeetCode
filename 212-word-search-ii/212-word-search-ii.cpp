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
    vector<vector<int>> dir= {{0,1}, {1,0}, {-1,0}, {0,-1}};
  
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
  
    void solve(int i, int j, vector<vector<char>> &board, vector<string> &ans){
      dfs(i, j, root, board, "", ans);
    }

    void dfs(int i, int j, Node* node, vector<vector<char>> &b, string word, vector<string> &ans){
      // array out of bound or trie doesn't contain character or visited cell
      if(i<0 || j<0 || i==b.size() || j==b[0].size() || b[i][j]=='#' || !node->links[b[i][j]-'a']) return;
      
      // add the current charcter to the word
      word+= b[i][j];
      
      // if end of a word is reached
      node= node->getNextNode(b[i][j]);
      if(node->flag){
        ans.push_back(word);
        node->flag= false;
      }
  
      char ch= b[i][j];
      // apply dfs in all 4 directions
      for(auto &d: dir){
        b[i][j]= '#';
        dfs(i+d[0], j+d[1], node, b, word, ans);
        b[i][j]= ch;
      }
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        vector<string> ans;
        
        for(auto &word: words) trie.insert(word);
      
        int n= board.size(), m= board[0].size();
        
        for(int i=0; i<n; ++i){
          for(int j=0; j<m; ++j){
            trie.solve(i, j, board, ans);
          }
        }
      
      return ans;
    }
};