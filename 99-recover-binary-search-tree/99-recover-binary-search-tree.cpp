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
    void inorder(TreeNode* root, vector<pair<int,TreeNode*>> &io){
      if(!root) return;
      inorder(root->left, io);
      io.push_back({root->val, root});
      inorder(root->right, io);
    }
    void recoverTree(TreeNode* root) {
        vector<pair<int,TreeNode*>> io;
        inorder(root, io);
        auto sorted= io;
        sort(sorted.begin(), sorted.end());
        for(int i=0; i<io.size(); ++i){
          if(sorted[i].first!=io[i].first){
            swap(sorted[i].second->val, io[i].second->val);
            return;
          }
        }
    }
};