#include<bits/stdc++.h>

typedef unsigned long long int  ulli;
typedef long long int lli;

const int mod = 1e9+7;

using namespace std;

void solve() 
{
    lli a, b;
    cin >> a >> b;
    lli mx_excitement = abs(a - b);

    if(mx_excitement==0)
    {
        cout << 0 << " " << 0<<endl;
    }
    else if(a==0 || b==0)
    {
        cout << max(a,b) << " " << 0 << endl;
    }
    else
    {
        lli rem = a % mx_excitement;

        cout << mx_excitement <<" "<< min(rem, mx_excitement - rem);
        cout << endl;
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