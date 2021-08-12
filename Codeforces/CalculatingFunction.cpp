#include<bits/stdc++.h>

typedef unsigned long long int  ulli;
typedef long long int lli;

const int mod = 1e9+7;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
lli n, a;
    cin >> n;
    if(n % 2 == 0) a = n / 2;
    else a = -(n + 1) / 2;
    cout << a << endl;
    return 0;
}