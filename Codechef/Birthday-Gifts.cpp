#include<bits/stdc++.h>

typedef unsigned long long int  ulli;
typedef long long int lli;

const int mod = 1e9+7;

using namespace std;

void solve()
{
    lli n,k;
    cin>>n>>k;
    lli a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    sort(a, a + n, greater<int>());
    lli sum1=0;
    lli sum2=0;

    int turns=2*k;

    for(int i=0;i<turns-1;i++)
    {
        if(i%2==0)
        {
            sum1+=a[i];
        }
        else
        {
            sum2+=a[i];
        }
        
    }
    
    sum2+=a[turns-1]+ a[turns];

    cout<<max(sum2,sum1)<<endl;
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