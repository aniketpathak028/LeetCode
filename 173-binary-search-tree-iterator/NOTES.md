**Pre computing the inorder traversal O(N)**
```
vector<int> inorder;
int ptr;
BSTIterator(TreeNode* root) {
findinorder(root, inorder);
ptr= -1;
}
int next() {
ptr++;
return inorder[ptr];
}
bool hasNext() {
int size= inorder.size()-1;
return ptr < size ? 1 : 0;
}
void findinorder(TreeNode* root, vector<int> &inorder){
if(!root) return;
findinorder(root->left, inorder);
inorder.push_back(root->val);
findinorder(root->right, inorder);
}
```
​
​