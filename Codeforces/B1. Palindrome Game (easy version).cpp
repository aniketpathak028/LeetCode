#include<bits/stdc++.h>

typedef unsigned long long int  ulli;
typedef long long int lli;

const int mod = 1e9+7;

using namespace std;


void solve()
{

    int n;
    cin>>n;
    string s;
    cin>>s;
    int one=0,zero=0;
    for(auto i : s)
    {
        if(i=='0') zero++;
        else one++;
    }
    if(zero==1 || zero%2==0) cout<<"BOB"<<"\n";
    else cout<<"ALICE"<<"\n";
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

