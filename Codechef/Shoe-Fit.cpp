#include <bits/stdc++.h>

typedef unsigned long long int ulli;
typedef long long int lli;

const int mod = 1e9 + 7;

using namespace std;

void solve()
{
    int a, b, c;

    cin >> a >> b >> c;

    if (a == b && b == c)
    {
        cout << 0 << endl;
    }
    else
        cout << 1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}