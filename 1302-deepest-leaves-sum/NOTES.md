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