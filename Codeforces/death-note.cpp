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
    cin>>n>>m;
    int a[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int sum=0;
    int ans[n];

    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        ans[i]= sum/m;

        sum= sum%m;
    }

    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}