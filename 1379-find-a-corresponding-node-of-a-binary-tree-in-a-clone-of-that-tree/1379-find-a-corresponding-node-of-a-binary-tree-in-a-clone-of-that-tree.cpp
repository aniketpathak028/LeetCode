/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* findNode(TreeNode* cloned, int val){
      if(!cloned) return NULL;
      if(cloned->val==val) return cloned;
      
      if(findNode(cloned->left, val)) return findNode(cloned->left, val);
      else return findNode(cloned->right, val); 
    }
  
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return findNode(cloned, target->val);
    }
};