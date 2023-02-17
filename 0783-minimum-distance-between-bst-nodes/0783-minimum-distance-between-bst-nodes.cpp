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
    void preorder(TreeNode* root, vector<int> &p){
        if(!root) return;
        p.push_back(root->val);
        preorder(root->left, p);
        preorder(root->right, p);
    }
    
    int minDiffInBST(TreeNode* root) {
        vector<int> pre;
        preorder(root, pre);
        int mini= INT_MAX;
        for(int i=0; i<pre.size(); ++i){
            for(int j=i+1; j<pre.size(); ++j){
                mini= min(mini, abs(pre[j]-pre[i]));
            }
        }
        return mini;
    }
};