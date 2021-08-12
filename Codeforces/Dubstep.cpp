#include<bits/stdc++.h>

typedef unsigned long long int  ulli;
typedef long long int lli;

const int mod = 1e9+7;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    for(int i=0;i<s.size();)
    {
        if(s[i]=='W' && s[i+1]=='U' && s[i+2]=='B')
        {
            cout<<" ";
            i=i+3;
        }
        else
        {
            cout<<s[i];
            i++;
        }
    }
    return 0;
}