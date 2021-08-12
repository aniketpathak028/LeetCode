#include<bits/stdc++.h>

typedef unsigned long long int  ulli;
typedef long long int lli;

const int mod = 1e9+7;

using namespace std;

void solve() 
{
    int x1, y1;
    int x2, y2;
    int f1, f2;

    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> f1 >> f2;

    int ans = abs(y2-y1) + abs(x2 - x1);

    if(x1==x2 || y1==y2)
    {
        if(f1==x1)
        {
            if(f2>min(y1,y2)&&f2<max(y1,y2))
            {
                ans += 2;
            }

        }
        else if (f2 == y1)
        {
            if (f1 > min(x1, x2) && f1 < max(x1, x2))
            {
                ans += 2;
            }
        }
    }

    cout << ans<<endl;

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