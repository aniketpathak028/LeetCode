#include<bits/stdc++.h>

typedef unsigned long long int  ulli;
typedef long long int lli;

const int mod = 1e9+7;

using namespace std;

void solve()
{
    int n,m,i,j;
    cin>>n>>m;
    cin>>i>>j;

    int x1,x2,y1,y2;
    
    int mid1= n/2;
    int mid2= m/2;

    if(i<= mid1 && j<= mid2)
    {
        x1=1;
        y1=m;
        x2=n;
        y2=1;
    }
    else if(i>=mid1 && j>=mid2)
    {
        x1=1;
        y1=m;
        x2=n;
        y2=1;
    }
    else
    {
        x1=1;
        y1=1;
        x2=n;
        y2=m;
    }

    cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2;
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