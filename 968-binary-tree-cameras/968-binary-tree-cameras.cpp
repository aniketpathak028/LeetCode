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
    int solve(TreeNode* root, int &cameras){
      if(!root) return 1;
      
      int left= solve(root->left, cameras);
      int right= solve(root->right, cameras);
      
      if(left==-1 || right==-1){
        cameras++;
        return 0;
      }
      
      if(left==0 || right==0) return 1;
      
      return -1;
    }
  
    int minCameraCover(TreeNode* root) {
        int cameras= 0;
        if(solve(root, cameras)==-1) return ++cameras;
        return cameras;
    }
};