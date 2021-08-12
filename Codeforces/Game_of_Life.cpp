#include<bits/stdc++.h>

typedef unsigned long long int  ulli;
typedef long long int lli;

const int mod = 1e9+7;

using namespace std;

void solve()
{
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int j=0;j<m;j++)
    {
         for(int i=0;i<n;i++)
            {
                if(i==1)
                {
                    if(a[i+1]==1)
                    {
                        a[i]=1;
                    }
                }
                else if(i==n-1)
                {
                    if(a[i-1]==1)
                    {
                        a[i]=1;
                    }
                }
                else
                {
                    if(a[i-1]==1 || a[i+1]==1)
                {
                    a[i]=1;
                }
                }
               
            }
    }

    for(int i=0;i<n;i++)
    {
        cout<<a[i];
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