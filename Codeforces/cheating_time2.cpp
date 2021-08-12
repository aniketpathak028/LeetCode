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

    int time=0;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            time+=s[i]-0;
        }
        else if(i==n-1)
        {
            time+=f-e[i];
        }
        else
        time+=e[i]-s[i];
    }

    int cheating_time= f-time;
    if(cheating_time>=k)
    {
        cout<<"YES"<<endl;
    }
    else{
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