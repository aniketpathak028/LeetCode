#include <bits/stdc++.h>

typedef unsigned long long int ulli;
typedef long long int lli;

const int mod = 1e9 + 7;

using namespace std;

void solve()
{
    int k, n, m;
    cin >> k >> n >> m;
    int a[n];
    int b[m];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < m; i++)
        cin >> b[i];

    int i = 0;
    int j = 0;

    int lines = k;

    vector<int> ans;

    bool is_poss = true;

    while(i<n && j<m)
    {
        if(a[i] == 0)
        {
            ans.push_back(a[i]);
            i++;
            k++;
        }
        else if(b[j]== 0)
        {
            ans.push_back(b[j]);
            j++;
            k++;
        }
        else
        {
            if(a[i]<b[j])
            {
                if (a[i] <= k)
                {
                    ans.push_back(a[i]);
                    i++;
                }
                else
                {
                    is_poss = false;
                    break;
                }
            }
            else if(b[j]<a[i])
            {
                if(b[j] <= k)
                {
                    ans.push_back(b[j]);
                    j++;
                }      
                else
                {
                    is_poss = false;
                    break;
                }
            }
        }
    }

    while(i<n)
    {
        if (a[i] == 0)
        {
            ans.push_back(a[i]);
            i++;
            k++;
        }
        else 
        {
            if (a[i] <= k)
            {
                ans.push_back(a[i]);
                i++;
            }
            else
            {
                is_poss = false;
                break;
            }
        }
    }

    while(j<m)
    {
        if (b[j] == 0)
        {
            ans.push_back(b[j]);
            j++;
            k++;
        }
        else 
        {
            if (b[j] <= k)
            {
                ans.push_back(b[j]);
                j++;
            }
            else
            {
                is_poss = false;
                break;
            }
        }
    }

    if(is_poss)
    {
        for(auto a: ans)
            cout << a<<" ";

        cout << endl;
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
        solve();
    return 0;
}