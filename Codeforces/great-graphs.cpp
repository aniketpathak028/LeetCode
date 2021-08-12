#include<bits/stdc++.h>

typedef unsigned long long int  ulli;
typedef long long int lli;

const int mod = 1e9+7;

using namespace std;

void solve() 
{
    int n;
    cin>>n;

    lli a[n];
    for(lli i=0;i<n;i++) cin>>a[i];

    sort(a, a+n);
    lli sum= a[n-1];

    lli neg[n];
    neg[0]= 0;

    for(lli i=1;i<n;i++)
    {
        neg[i]= neg[i-1]+ i*(a[i]-a[i-1]);
        sum-= neg[i];
    }

    cout<<sum<<endl;
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