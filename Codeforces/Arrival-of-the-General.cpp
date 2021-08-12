#include<bits/stdc++.h>

typedef unsigned long long int  ulli;
typedef long long int lli;

const int mod = 1e9+7;

using namespace std;

void solve()
{
    int n;
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int swap1= distance(a, max_element(a, a + n));

    reverse(a, a + n);

    int swap2=distance(a, min_element(a, a + n));
    swap2= n-swap2-1;

    if(swap1>swap2)
        {
	        cout<<(swap1-1)+(n-swap2)-1;
        }
    else
        {
	        cout<<(swap1-1)+(n-swap2);
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}