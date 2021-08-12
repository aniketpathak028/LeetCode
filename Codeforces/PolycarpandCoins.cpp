#include<bits/stdc++.h>

typedef unsigned long long int  ulli;
typedef long long int lli;

const int mod = 1e9+7;

using namespace std;

void solve()
{
    lli n;
    cin >> n;

    if(n%3 == 0)
    {
        cout << n / 3 << " " << n / 3<<endl;
    }
    else
    {
        cout << n- (n/3) << " " << n / 3<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}