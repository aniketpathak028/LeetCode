#include <bits/stdc++.h>

typedef unsigned long long int ulli;
typedef long long int lli;

const int mod = 1e9 + 7;

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int a[n], b[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
        cin >> b[i];

    int sum[n];

    for (int i = 0; i < n; i++)
        sum[i] = b[i] - a[i];

    int sum2 = 0;

    for (int i = 0; i < n; i++)
        sum2 += sum[i];

    if (sum2 == 0)
    {
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            if (sum[i] > 0)
                c += sum[i];
        }

        cout << c << endl;

        for (int i = 0; i < n; i++)
        {
            if(sum[i]<0)
            {
                for (int j = i + 1; j < n;j++)
                {
                    if(sum[j]>0)
                    {
                        while(sum[j]!=0 && sum[i]!=0)
                        {
                            sum[j]--;
                            sum[i]++;
                            cout << i+1 << " " << j+1 << endl;
                        }
                    }
                }
            }
            else if(sum[i]>0)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (sum[j] < 0)
                    {
                        while (sum[j] != 0 && sum[i] != 0)
                        {
                            sum[j]++;
                            sum[i]--;
                            cout << j+1 << " " << i+1 << endl;
                        }
                    }
                }
            }
        }
    }
    else
    {
        cout << -1 << endl;
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