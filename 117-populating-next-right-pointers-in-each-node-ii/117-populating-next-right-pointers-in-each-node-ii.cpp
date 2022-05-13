/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    vector<vector<Node*>> bfs(Node* root){
      vector<vector<Node*>> ans; // vector to store level order traversal
      if(!root) return ans;
      queue<Node*> q;
      q.push(root);
      while(!q.empty()){
        int size= q.size();
        vector<Node*> level;
        for(int i=0; i<size; ++i){
          auto node= q.front();
          q.pop();
          level.push_back(node);
          // push the nodes for the next level
          if(node->left) q.push(node->left);
          if(node->right) q.push(node->right);
        }
        ans.push_back(level);
      }
      return ans;
    }
  
    Node* connect(Node* root) {
       auto bfs_store= bfs(root);
       // setting the next pointers level by level
       
       for(auto level: bfs_store){
         for(int i=0; i<level.size()-1; ++i){
           level[i]->next= level[i+1];
         }
         level[level.size()-1]->next= NULL;
       }
      
       return root;
    }
};