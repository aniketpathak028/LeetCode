#include<bits/stdc++.h>

typedef unsigned long long int  ulli;
typedef long long int lli;

const int mod = 1e9+7;

using namespace std;

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    int l[k];

    for(int i=0;i<k;i++)
    {
        cin>>l[i];
    }
    int count=0;
    int a[n]={0};

    for(int i=0;i<k;i++)
    {
        if(l[i]<=n && l[i]>=1)
        {
            a[l[i]-1]++;
        }
    }

    for(int i=0;i<n;i++)
    {
        if(a[i]>1)
        {
            count++;
        }
    }

    cout<<count<<" ";

    for(int i=0;i<n;i++)
    {
        if(a[i]>1)
        {
            cout<<i+1<<" ";
        }
    }


    cout<<endl;
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