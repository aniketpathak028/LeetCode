#include<bits/stdc++.h>

typedef unsigned long long int  ulli;
typedef long long int lli;

const int mod = 1e9+7;

using namespace std;

const int N = 1e7 + 2;

vector<bool> prime(N, true);
vector<int> prime_till_N(N);


void sieve()
{
	prime[0] = prime[1] = false;
	int i, j;
	for (i = 2; i * i < N; i++)
	{
		if (prime[i])
		{
			for (j = i * i; j <= N; j += i)
				prime[j] = false;
		}
	}
}

void pre() {
	int i, count = 0;
	for (i = 1; i <= N; i++) {
		if (prime[i])
			count++;
		prime_till_N[i] = cnt;
	}
}

void solve()
{
        int n;
		cin >> n;
		if (n == 2)
			cout << 1 << "\n";
		else if (n == 3)
			cout << 2 << "\n";
		else
		{
			int lim = n / 2;
			int extra = prime_till_N[n] - prime_till_N[lim];
			int groups = extra + 1;
			cout << groups << "\n";
		}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
	pre();


    lli t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}