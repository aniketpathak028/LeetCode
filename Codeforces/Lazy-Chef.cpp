#include<bits/stdc++.h>

typedef unsigned long long int  ulli;
typedef long long int lli;

const int mod = 1e9+7;

using namespace std;

void solve()
{
    int x,m,d;
    cin>>x>>m>>d;
    if(x*m<= x+d)
    {
        cout<<x*m<<endl;
    }
    else
    {
        cout<<min(x*m,x+d)<<endl;
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