#include<bits/stdc++.h>

typedef unsigned long long int  ulli;
typedef long long int lli;

const int mod = 1e9+7;

using namespace std;

void solve()
{
    lli r,b,d;
    cin>>r>>b>>d;
    if(abs(r-b)<=d){
        cout<<"YES"<<"\n";
        return;
    }
    if(r>b) swap(r,b);
    if(r*(d+1LL)<b){
        cout<<"NO"<<"\n";
    }
    else{
        cout<<"YES"<<"\n";
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