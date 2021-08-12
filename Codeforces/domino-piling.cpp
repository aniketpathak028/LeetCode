
#include<bits/stdc++.h>

typedef unsigned long long int  ulli;
typedef long long int lli;

const int mod = 1e9+7;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    int ans;
    cin>>m>>n;
    ans=n/2*m;
    if(n%2)
    ans+=m/2;
    cout<<ans;
    return 0;
}