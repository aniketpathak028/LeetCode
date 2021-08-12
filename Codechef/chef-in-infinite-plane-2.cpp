#include <bits/stdc++.h>

typedef unsigned long long int ulli;
typedef long long int lli;

const int mod = 1e9 + 7;

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int a[n];

    unordered_map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        m[a[i]]++;
    }

    int ans = 0;

    for (auto i : m)
    {
        if (i.second == 1)
        {
            ans++;
        }
        else
        {
            if (i.second <= i.first-1)
            {
                ans += i.second;
            }
            else
            {
                ans += i.first-1;
            }
        }
    }

    cout << ans << endl;
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
