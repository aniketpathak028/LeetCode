#include<bits/stdc++.h>

typedef unsigned long long int  ulli;
typedef long long int lli;

const int mod = 1e9+7;

using namespace std;

int getIndex(vector<char> v, char K)
{
    auto it = find(v.begin(), v.end(), K);
 
    if (it != v.end())
    {
     
    
        int index = it - v.begin();
        return index;
    }
    else {
      
        return -1;
    }
}

int solve(string s)
{
    int l,r;
    cin>>l>>r;

    vector<char> v;

    for(int i=l-1;i<r;i++)
    {
        char c= s[i];
        v.push_back(c);
    }

    unordered_set <char> set;
    int count=0;

    for(int i=0;i<v.size();i++)
    {
        if(set.find(v[i])!=set.end())
        {
             int number= getIndex(v,v[i])+1;
             count+=number;
        }
        else
        {
            int index= getIndex(v,v[i])+1;
            count+=index;
            set.insert(v[i]);
        }
    }

    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    for(int i=0;i<q;i++)
    {
        cout<<solve(s)<<endl;
    }
    return 0;
}