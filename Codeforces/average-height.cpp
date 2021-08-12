#include<bits/stdc++.h>

typedef unsigned long long int  ulli;
typedef long long int lli;

const int mod = 1e9+7;

using namespace std;

    void solve()
{
	int n;
	cin>>n;
	vector<int>v;
	vector<int>v1;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		if(x%2==0)v.push_back(x);
		else v1.push_back(x);
	}
	for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
		for(int i=0;i<v1.size();i++) cout<<v1[i]<<" ";
			cout<<endl;
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