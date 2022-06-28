struct Node{
  Node* links[2];
  
  bool containsKey(int bit){
    return links[bit]!=NULL;
  }
  
  void createRef(int bit){
    links[bit]= new Node();
  }
  
  Node* getNextNode(int bit){
    return links[bit];
  }
};

class Trie{
  private:
    Node* root;
  
  public:
    Trie(){
      root= new Node();
    }
  
    void insert(int num){
      Node* node= root;
      for(int bit= 31; bit>=0; --bit){
        bool isSet= num & (1<<bit);
        if(!node->containsKey(isSet)) node->createRef(isSet);
        node= node->getNextNode(isSet);
      }
    }
  
    int getMaxXOR(int val){
      int maxi= 0;
      Node* node= root;
      for(int bit= 31; bit>=0; --bit){
        bool isSet= val & (1<<bit);
        if(node->containsKey(!isSet)){
          maxi= maxi | (1<<bit);
          node= node->getNextNode(!isSet);
        }else{
          node= node->getNextNode(isSet);
        }
      }
      return maxi;
    }
};


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxi= 0;
        Trie* obj= new Trie();
        
        for(int &num: nums) obj->insert(num);
      
        for(int &num: nums) maxi= max(maxi, obj->getMaxXOR(num));
      
        return maxi;
    }
};