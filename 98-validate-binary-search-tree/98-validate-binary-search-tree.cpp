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
    bool checkLeft(TreeNode* root, int ele){
      if(!root) return true;
      if(root->val<ele) return checkLeft(root->left, ele) && checkLeft(root->right, ele);
      return false;
    }
  
    bool checkRight(TreeNode* root, int ele){
      if(!root) return true;
      if(root->val>ele) return checkRight(root->left, ele) && checkRight(root->right, ele);
      return false;
    }
  
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        
        if(checkLeft(root->left, root->val) && checkRight(root->right, root->val)) return isValidBST(root->left) && isValidBST(root->right);
      
      return false;
    }
};