#include<bits/stdc++.h>

typedef unsigned long long int  ulli;
typedef long long int lli;

const int mod = 1e9+7;

using namespace std;

void solve()
{
    int n;
    cin>>n;
    if(n%2==0)
    {
        for(int i=1;i<=n;i++)
        {
            if(i%2==0)
            cout<<i-1<<" ";
            else
            cout<<i+1<<" ";
        }
    }
    else{
        for(int i=1;i<=n-1;i++)
        {
            if(i%2==0)
            {
                if(i==n-1)
                cout<<n<<" ";
                else
                cout<<i-1<<" ";
            }
            else
            cout<<i+1<<" ";
        }
        cout<<n-2;
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