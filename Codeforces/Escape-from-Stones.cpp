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
    
    for(int i=0;i<s.length();i++)
    {
        if(s[i]== 'r')
        cout<<i+1<<endl;
    }

    for(int i=s.length()-1;i>-1;i--)
    {
        if(s[i]== 'l')
        cout<<i+1<<endl;
    }

    return 0;
}