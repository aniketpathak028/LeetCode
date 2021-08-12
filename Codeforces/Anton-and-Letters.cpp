
#include<bits/stdc++.h>

typedef unsigned long long int  ulli;
typedef long long int lli;

const int mod = 1e9+7;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string n;
    int ar[123], sum = 0;
    getline(cin, n);
    for (int i = 1; i < n.size(); i += 3) {
        ar[(int) n[i]] = 1;
    }
    for (int i = 0; i < 123; i++) {
        sum += ar[i];
    }
    cout << sum;
}