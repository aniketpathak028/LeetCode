```
struct Node{
Node* links[26];
bool flag;
bool containsKey(char ch){
return links[ch-'a']!=NULL;
}
void createRef(char ch){
links[ch-'a']= new Node();
}
Node* getNextNode(char ch){
return links[ch-'a'];
}
};
​
class Trie{
private:
Node* root;
vector<vector<int>> dir= {{0,1}, {1,0}, {-1,0}, {0,-1}};
public:
Trie(){
root= new Node();
}
void insert(string word){
Node* node= root;
for(int i=0; i<word.size(); ++i){
if(!node->containsKey(word[i])) node->createRef(word[i]);