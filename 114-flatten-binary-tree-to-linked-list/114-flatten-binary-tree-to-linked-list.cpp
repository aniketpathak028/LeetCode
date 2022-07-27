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
class Solution {
public:
    void pre(TreeNode* root, vector<int> &preorder){
      if(!root) return;
      preorder.push_back(root->val);
      pre(root->left, preorder);
      pre(root->right, preorder);
    }
  
    void flatten(TreeNode* root) {
        vector<int> preorder;
        pre(root, preorder);
      
        TreeNode* node= root;

        for(int i=0; i<preorder.size(); ++i){
          if(node->left) node->left= NULL;
          node->val= preorder[i];
          if(i!=preorder.size()-1 && !node->right) node->right= new TreeNode();
          node= node->right;
        }
    }
};