#include <bits/stdc++.h>

typedef unsigned long long int ulli;
typedef long long int lli;

const int mod = 1e9 + 7;

using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int i = 0;
    int j = n - 1;

    char c = 'a' + n - 1;

    bool ans = true;

    while (i <= j)
    {
        if (s[i] == c)
        {
            i++;
            c--;
        }
        else if (s[j] == c)
        {
            j--;
            c--;
        }
        else
        {
            ans = false;
            break;
        }
    }
    if (ans)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}