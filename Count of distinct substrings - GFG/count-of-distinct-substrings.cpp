// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int countDistinctSubstring(string s);

int main()
{
 int t,l,i,j;
 int temp;
    cin>>t;
 while(t--){
 string s;
  cin>>s;
  cout<<countDistinctSubstring(s)<<endl;

 }
}

// } Driver Code Ends

struct Node{
    Node* links[26];
    
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    
    Node* getNextNode(char ch){
        return links[ch-'a'];
    }
    
    void createRef(char ch){
        links[ch-'a']= new Node();
    }
};

/*You are required to complete this method */
int countDistinctSubstring(string s)
{
    Node *root= new Node(), *node;
    int cnt= 0;
    for(int i=0; i<s.size(); ++i){
        node= root;
        for(int j=i; j<s.size(); ++j){
            if(!node->containsKey(s[j])){
               node->createRef(s[j]);
               cnt++;
            } 
            node= node->getNextNode(s[j]);
        }
    }
    return cnt+1;
}