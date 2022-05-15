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
pair<int, int> deepestNodeSum (TreeNode* root){
if(!root) return {0,0};
if(root->left==NULL && root->right==NULL){
return {root->val, 1};
}
pair<int, int> left, right;
if(root->left){
left = deepestNodeSum(root->left);
}
if(root->right){
right = deepestNodeSum(root->right);
}
if(left.second==right.second){
return {left.first+right.first, 1+left.second};
}
else{
if(left.second>right.second){
return {left.first, 1+left.second};
}else{
return {right.first, 1+right.second};
}
}
}
int deepestLeavesSum(TreeNode* root) {
pair<int, int> ans = deepestNodeSum(root);
return ans.first;
}