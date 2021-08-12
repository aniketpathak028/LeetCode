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
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    int ans = 2;
    if (std::is_sorted(a, a + n))
      ans = 0;
    else if (a[0] == 1 || a[n - 1] == n)
      ans = 1;
    else if (a[0] == n && a[n - 1] == 1)
      ans = 3;
    cout<<ans<<endl;
  
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