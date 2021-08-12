#include<bits/stdc++.h>

typedef unsigned long long int  ulli;
typedef long long int lli;

const int mod = 1e9+7;

using namespace std;

void solve() 
{
    lli n;
    cin >> n;
    lli a[n];
    lli sum = 0;
    for (lli i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if(sum%n== 0)
    {
        cout << 0 << endl;
    }
    else if(sum<n)
    {
        cout << sum*(n-sum) << endl;
    }
    else
    {
        lli el = sum / n;
        lli rem = sum % n;
        cout << rem * (n - rem) << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli t;
    cin>>t;
    while(t--)
    {
     solve();
    }
    return 0;
}