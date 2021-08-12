#include<bits/stdc++.h>

typedef unsigned long long int  ulli;
typedef long long int lli;

const int mod = 1e9+7;

using namespace std;
void solve()
{
    int k;
    cin>>k;
    string s[k];
    for(int i=0;i<k;i++)
    {
        cin>>s[i];
    }

    int flag=1;
    for(int i=0;i<k;i++)
    {
        string x= s[i];
        for(int j=0;j<x.size;j++)
        {
            if(flag!=-1)
            {
                  if(s[j]>=97 && s[j]<=109 || s[j]>=78 && s[j]=< 90)
            {
                continue;
            }
            else
            {
                flag=-1;
                cout<<"NO"<<endl;
            }
            }
          
        }
    }

    if(flag==0)
    {
        cout<<"YES"<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}