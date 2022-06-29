class Node{
public:
       int c;
       int minima;
       Node* children[2];
};
Node *getNode(int c)
{
         Node *node=new Node();
         node->c=c;
         node->minima=INT_MAX;
         for(int i=0;i<2;i++)
         {
             node->children[i]=NULL;
         }
         return node;
}
class Trie{
private:
    Node *root;
public:
    Trie()
    {
        root=getNode(2);
    }
    Node *cur;
    int x,res;
    vector<int> calculate(vector<int>& nums,vector<vector<int>>& q)
    {
        for(int i=0;i<nums.size();i++)
        {
            cur=root;
            for(int j=31;j>=0;j--)
            {
                if(nums[i]&(1<<j))
                    x=1;
                else
                    x=0;
                if(cur->children[x]==NULL)
                {
                    cur->children[x]=getNode(x);
                }
                cur=cur->children[x];
                cur->minima=min(cur->minima,nums[i]);
            }
        }
        int m=q.size();
        vector<int> ans(m);
        for(int i=0;i<q.size();i++)
        {
            cur=root;
            res=0;
            for(int j=31;j>=0;j--)
            {
                if(q[i][0]&(1<<j))
                    x=1;
                else
                    x=0;
                if(cur->children[x^1]!=NULL && (cur->children[x^1]->minima )<=q[i][1])
                {
                    res=(res|(1<<j));
                    cur=cur->children[x^1];
                }
                else if(cur->children[x]!=NULL && cur->children[x]->minima<=q[i][1])
                    cur=cur->children[x];
                else
                {
                    res=-1;
                    break;
                }
            }
            ans[i]=res;
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie trie;
        return trie.calculate(nums,queries);
    }
};