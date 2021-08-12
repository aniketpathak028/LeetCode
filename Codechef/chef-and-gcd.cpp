#include <bits/stdc++.h>

typedef unsigned long long int ulli;
typedef long long int lli;

const int mod = 1e9 + 7;

using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;

    return gcd(b % a, a);
}

void solve()
{
    int x, y;
    cin >> x >> y;

    if (gcd(x, y) > 1)
    {
        cout << 0 << endl;
    }
    else
    {
        if (x % 2 == 0 && y % 2 == 1)
        {
            cout << 1 << endl;
        }
        else if (x % 2 == 1 && y % 2 == 0)
        {
            cout << 1 << endl;
        }
        else if (x % 2 == 1 && y % 2 == 1)
        {
            if (gcd(max(x, y) + 1, min(x, y)) > 1)
            {
                cout << 1 << endl;
            }
            else if (gcd(min(x, y) + 1, max(x, y)) > 1)
            {
                cout << 1 << endl;
            }
            else
                cout << 2 << endl;
        }
    }
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