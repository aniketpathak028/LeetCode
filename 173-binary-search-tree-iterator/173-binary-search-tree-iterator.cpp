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
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    int next() {
        auto next_ele= st.top();
        st.pop();
        pushLeft(next_ele->right);
        return next_ele->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
  
    void pushLeft(TreeNode* root){
      while(root!=NULL){
        st.push(root);
        root= root->left;
      }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */