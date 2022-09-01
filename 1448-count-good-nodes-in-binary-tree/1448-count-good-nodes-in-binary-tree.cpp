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
    int count(TreeNode* root, int currMax){
        if(!root) return 0;
        
        if(currMax<=root->val) return 1+count(root->left, root->val)+count(root->right, root->val);
        else return count(root->left, currMax)+count(root->right, currMax);
    }
    
    int goodNodes(TreeNode* root) {
        return count(root, INT_MIN);
    }
};