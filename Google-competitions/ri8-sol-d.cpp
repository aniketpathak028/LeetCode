
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, i, j, ans, l, c, k;

    cin >> t;

    for (j = 1; j <= t; j++)
    {
        ans = 0;
        int g[3][3];
        vector<int> p;

        cin >> g[0][0] >> g[0][1] >> g[0][2];
        cin >> g[1][0] >> g[1][2];
        cin >> g[2][0] >> g[2][1] >> g[2][2];

        if (g[0][0] - g[0][1] == g[0][1] - g[0][2])
            ans++;

        if (g[2][0] - g[2][1] == g[2][1] - g[2][2])
            ans++;

        if (g[0][0] - g[1][0] == g[1][0] - g[2][0])
            ans++;

        if (g[0][2] - g[1][2] == g[1][2] - g[2][2])
            ans++;

        if (abs(g[1][0] - g[1][2]) % 2 == 0)
        {
            p.push_back((g[1][0] + g[1][2]) / 2);
        }
        if (abs(g[0][1] - g[2][1]) % 2 == 0)
        {
            p.push_back((g[0][1] + g[2][1]) / 2);
        }
        if (abs(g[0][0] - g[2][2]) % 2 == 0)
        {
            p.push_back((g[0][0] + g[2][2]) / 2);
        }
        if (abs(g[2][0] - g[0][2]) % 2 == 0)
        {
            p.push_back((g[2][0] + g[0][2]) / 2);
        }

        sort(p.begin(), p.end());

        l = p.size();
        c = 0;
        for (i = 0; i < l;)
        {
            k = i;
            while (p[i] == p[k] && i < l)
            {
                i++;
            }
            c = max(c, i - k);
        }
        ans = ans + c;

        cout << "Case #" << j << ": " << ans << "\n";
    }
}
