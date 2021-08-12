#include<bits/stdc++.h>

typedef unsigned long long int  ulli;
typedef long long int lli;

const int mod = 1e9+7;

using namespace std;

void solve() 
{
    int n;
    cin>>n;
    lli a[n+1];

    for(int i=1;i<n+1;i++)
    cin>>a[i];

    int ans= 0;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=a[i]-i;j<=n;j+=a[i])
        {
            if(j>=0)
                if(a[j]*a[i]== i+j && i<j)
                ans++;
        }
    }

    cout<<ans<<endl;

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