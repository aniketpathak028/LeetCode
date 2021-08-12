#include<bits/stdc++.h>

typedef unsigned long long int  ulli;
typedef long long int lli;

const int mod = 1e9+7;

using namespace std;

void solve()
{
    int n;
    cin>>n;
    int bitwise_and=n;
    
    for(int i=n;i>0;i--)
    {
        bitwise_and= bitwise_and & (n-1);
        if(bitwise_and==0)
        {
            cout<<n;
            break;
        }
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