#include <bits/stdc++.h>

typedef unsigned long long int ulli;
typedef long long int lli;

const int mod = 1e9 + 7;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli t;
    cin >> t;
    for (lli i = 1; i <= t; i++)
    {
        lli g00, g01, g02;
        lli g10, g12;
        lli g20, g21, g22;

        cin >> g00 >> g01 >> g02;
        cin >> g10 >> g12;
        cin >> g20 >> g21 >> g22;

        int ans = 0;

        if (2*g01 == (g00 + g02))
        {
            ans++;
        }
        if (2*g21 == (g20 + g21))
        {
            ans++;
        }
        if (2*g10 == (g00 + g20))
        {
            ans++;
        }
        if (2*g12 == (g02 + g22))
        {
            ans++;
        }

        map<lli, int> m;

        if ((g00 + g22) % 2 == 0)
        {
            m[g00 + g22]++;
        }
        if ((g02 + g20) % 2 == 0)
        {
            m[g02 + g20]++;
        }
        if ((g10 + g12) % 2 == 0)
        {
            m[g10 + g12]++;
        }
        if ((g01 + g21) % 2 == 0)
        {
            m[g01 + g21]++;
        }

        int res = 0;
        for (auto it : m)
        {
            if (it.second > res)
                res = it.second;
        }

        ans += res;

        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}
