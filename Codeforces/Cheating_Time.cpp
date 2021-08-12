#include<bits/stdc++.h>

typedef unsigned long long int  ulli;
typedef long long int lli;

const int mod = 1e9+7;

using namespace std;
void solve()
{
    int n,k,f;
    cin>>n>>k>>f;
    int s[n];
    int e[n];

    for(int i=0;i<n;i++)
    {
        cin>>s[i]>>e[i];
    }

    int time[n+1];
    for(int i=0;i<n+1;i++)
    {
        if(i==0)
        {
            time[i]= s[i]-0;
        }
        else if(i==n)
        {
            time[i]= f- e[i-1];
        }
        else
        {
            time[i]=s[i]-e[i-1];
        }
    }

    int flag= 1;
    for(int j=0;j<n+1;j++)
    {
        if(time[j]>=k)
        {
            flag=-1;
            break;
        }
    }

    if(flag==-1)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
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