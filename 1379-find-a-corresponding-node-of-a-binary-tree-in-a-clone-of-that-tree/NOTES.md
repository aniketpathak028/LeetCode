TreeNode* ans;
void findNode(TreeNode* cloned, int &toBeFound){
if(cloned->val==toBeFound) {
ans = cloned;
return;
}
if(cloned->left) findNode(cloned->left, toBeFound);
if(cloned->right) findNode(cloned->right, toBeFound);
}
TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
int toBeFound = target->val;
findNode(cloned, toBeFound);
return ans;
}