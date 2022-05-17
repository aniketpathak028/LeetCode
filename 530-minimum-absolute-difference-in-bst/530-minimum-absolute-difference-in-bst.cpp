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
    void inorder(TreeNode* root, vector<int> &io){
      if(!root) return;
      
      inorder(root->left, io);
      io.push_back(root->val);
      inorder(root->right, io);
    }
  
    int getMinimumDifference(TreeNode* root) {
        vector<int> io;
        inorder(root, io);
        int ans= INT_MAX;
        for(int i=0; i<io.size()-1; ++i) ans= min(ans, abs(io[i]-io[i+1]));
        return ans;
    }
};