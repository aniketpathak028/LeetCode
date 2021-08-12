#include <bits/stdc++.h>

typedef unsigned long long int ulli;
typedef long long int lli;

const int mod = 1e9 + 7;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<int> ans;

        ans.push_back(1);

        for (int i = 1; i < n; i++)
        {
            int cnt = 1;
            for (int j = i - 1; j >= 0; j--)
            {
                if (s[j] < s[j+1])
                    cnt++;
                else
                    break;
            }
            ans.push_back(cnt);
        }

        cout << "Case #" << k << ": ";
        for (auto it : ans)
        {
            cout << it << " ";
        }

        cout << endl;
    }
    return 0;
}