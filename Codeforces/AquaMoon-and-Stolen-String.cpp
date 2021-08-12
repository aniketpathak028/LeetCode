#include<bits/stdc++.h>

typedef unsigned long long int  ulli;
typedef long long int lli;

const int mod = 1e9+7;

using namespace std;

void solve() 
{
    int n, m;
    cin >> n >> m;

    char s[n][m];

    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < m;j++)
        {
            cin >> s[i][j];
        }
    }

    char reos[n - 1][m];

    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> reos[i][j];
        }
    }

    for (int i = 0; i < n;i++)
    {
        int c=0;
        for (int j = 0; j < m;j++)
        {
            for (int k = 0; k < n - 1;k++)
            {
                if(s[i][j]== reos[k][j])
                {
                    c++;
                }
            }
        }
        if(c<m)
        {
            for (int j = 0; j < m;j++)
            {
                cout << s[i][j]<<endl;
            }
        }
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