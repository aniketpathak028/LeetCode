#include <bits/stdc++.h>

typedef unsigned long long int ulli;
typedef long long int lli;

const int mod = 1e9 + 7;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k, l, m, n, d;
    int cont = 0;

    cin >> k >> l >> m >> n >> d;
    cont = d;

    if (k == 1 || l == 1 || m == 1 || n == 1)
    {
        cout << d << endl;
    }
    else
    {
        for (int i = 1; i <= d; i++)
        {
            if ((i % k != 0) && (i % l != 0) && (i % m != 0) && (i % n != 0))
                cont--;
        }
        cout << cont << endl;
    }
    return 0;
}