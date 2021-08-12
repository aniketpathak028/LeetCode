
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long

ll solve()
{
    ll n,k;
    cin>>n>>k;
 
    string s;
    cin>>s;
 
    ll cnt=0;
    for(ll i=0;i<n/2;i++)
    {
        if(s[i]!=s[n-i-1])cnt++;
    }
 
    return abs(k-cnt);
}
 
int main()
{

	ll t;
	cin>>t;
	for(ll i=1;i<=t;i++)
	{
	    cout<<"Case #"<<i<<": ";
 
	    cout<<solve()<<endl;
	}
 
}