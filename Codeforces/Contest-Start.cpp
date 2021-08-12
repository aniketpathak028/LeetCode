#include<bits/stdc++.h>

typedef unsigned long long int  ulli;
typedef long long int lli;

const int mod = 1e9+7;

using namespace std;

void solve()
{
    lli n,x,t;
    cin>>n>>x>>t;
    lli count=0;
    lli lb[n];
    lli ub[n];
    for(int i=0;i<n;i++)
    {
        lb[i]= i*x;
        ub[i]= lb[i] + t;
    }

    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(lb[j]<=ub[i])
            {
                count++;
            }
        }
    }

    cout<<count<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli k;
    cin>>k;
    while(k--)
    {
        solve();
    }
    return 0;
}