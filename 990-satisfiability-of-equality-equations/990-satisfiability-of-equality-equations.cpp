class Solution {
public:
    char findParent(char ch, map<char,char> &parent){
      if(ch==parent[ch]) return ch;
      return parent[ch]= findParent(parent[ch], parent);    
    }
  
    bool equationsPossible(vector<string>& equations) {
        map<char,char> parent;
        // create 26 disjoint sets
        for(char i= 'a'; i<='z'; ++i)
          parent[i]= i;
        
        // equal-to case
        for(auto &eqn: equations){
          char c1= eqn[0], c2= eqn[3], c3= eqn[1];
          if(c3=='=') parent[findParent(c1, parent)]= findParent(c2, parent);
        }    
        
        // not equals case
        for(auto &eqn: equations){
          char c1= eqn[0], c2= eqn[3], c3= eqn[1];
          if(c3=='!') if(parent[findParent(c1, parent)]==parent[findParent(c2, parent)]) return false;
        }   
      
      return true;
    }
};