### BFS
* Find the level-order-traversal or bfs of the tree, return the sum of the last level
```
int deepestLeavesSum(TreeNode* root) {
vector<vector<int>> ans;
queue<TreeNode*> q;
q.push(root);
while(!q.empty()){
int size= q.size();
vector<int> level;
for(int i=0; i<size; ++i){
auto node= q.front();
q.pop();
level.push_back(node->val);
if(node->left) q.push(node->left);
if(node->right) q.push(node->right);
}
ans.push_back(level);
}
return accumulate(ans[ans.size()-1].begin(), ans[ans.size()-1].end(), 0);
}
```
### DFS
* Perform a dfs such that upon reaching a leaf node, the value of the node is returned with unity
* In a non-leaf node we check for both left and right, and consider the value with greater height
* Incase both the heights are same then we add up their values