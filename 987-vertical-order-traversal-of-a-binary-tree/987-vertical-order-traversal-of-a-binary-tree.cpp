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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,map<int,multiset<int>>> mpp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0, 0}});
        while(!q.empty()){
            auto node= q.front();
            q.pop();
            int x= node.second.first, y= node.second.second;
            TreeNode* curr= node.first;
            mpp[x][y].insert(curr->val);
            if(curr->left) q.push({curr->left,{x-1, y+1}});
            if(curr->right) q.push({curr->right, {x+1, y+1}});
        }
        for(auto it: mpp){
            vector<int> col;
            for(auto itt: it.second){
                col.insert(col.end(), itt.second.begin(), itt.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};