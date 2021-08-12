#include <bits/stdc++.h>

typedef unsigned long long int ulli;
typedef long long int lli;

const int mod = 1e9 + 7;

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);

    int AND = -1; // sets all bits of AND variable as 1

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        AND = AND & v[i];
    }

    int min= 0;
    for (int i = 0; i < n; i++)
    {
        min = min|(v[i] ^ AND);
    }

    cout << AND << " " << min << endl;
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