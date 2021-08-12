#include <bits/stdc++.h>

typedef unsigned long long int ulli;
typedef long long int lli;

const int mod = 1e9 + 7;

using namespace std;

lli solve()
{
    lli n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    lli goodnessCount = 0;
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - i + 1])
        {
            goodnessCount++;
        }
    }

    return abs(k - goodnessCount);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli t;
    cin >> t;
    for (lli i = 1; i <= t; i++)
    {
        cout << "CASE #" << i << ": ";

        cout << solve() << endl;
    }
    return 0;
}