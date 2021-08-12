#include<bits/stdc++.h>

typedef unsigned long long int  ulli;
typedef long long int lli;

const int mod = 1e9+7;

using namespace std;

void solve()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int sum= 0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
    }
    float avg= sum/n;

    if(sum==n)
    {
        cout<<0<<endl;
    }
    else if(sum>n)
        cout<<sum-n<<endl;
    
    else if(sum<n)
        {
            cout<<1<<endl;
        }
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