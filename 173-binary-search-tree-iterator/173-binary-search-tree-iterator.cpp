/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    vector<int> inorder;
    int ptr;
  
    BSTIterator(TreeNode* root) {
      findinorder(root, inorder);
      ptr= -1;
    }
    
    int next() {
        ptr++;
        return inorder[ptr];
    }
    
    bool hasNext() {
      int size= inorder.size()-1;
      return ptr < size ? 1 : 0;
    }
  
    void findinorder(TreeNode* root, vector<int> &inorder){
        if(!root) return;
      
        findinorder(root->left, inorder);
        inorder.push_back(root->val);
        findinorder(root->right, inorder);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */