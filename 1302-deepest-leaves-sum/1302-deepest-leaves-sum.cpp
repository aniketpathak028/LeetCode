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
    pair<int,int> dfs(TreeNode* root){
      if(!root) return {0,0}; // if null encountered return null pair
      
      // leaf-node
      if(!root->left && !root->right){
          return {root->val, 1};
      }
      // non-leaf-node
      else{
        auto left= dfs(root->left), right= dfs(root->right);
        if(left.second==right.second) return {left.first+right.first, left.second+1};
        else if(left.second>right.second) return {left.first, left.second+1};
        else return {right.first, right.second+1};
      }
    }
  
    int deepestLeavesSum(TreeNode* root) {
        auto ans= dfs(root);
        return ans.first;
    }
};