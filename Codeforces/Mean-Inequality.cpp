#include<bits/stdc++.h>

typedef unsigned long long int  ulli;
typedef long long int lli;

const int mod = 1e9+7;

using namespace std;

void solve()
{
    int n;
    cin>>n;
    int a[2*n];
    for(int i=0;i<2*n;i++)
    {
        cin>>a[i];
    }

    sort(a,a+2*n);

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" "<<a[2*n-1-i]<<" ";
    }
    cout<<"\n";
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