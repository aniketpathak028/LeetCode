#include<bits/stdc++.h>

typedef unsigned long long int  ulli;
typedef long long int lli;

const int mod = 1e9+7;

using namespace std;

int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0)
       return b;
    if (b == 0)
       return a;
  
    // base case
    if (a == b)
        return a;
  
    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

void solve()
{
    int k;
    cin>>k;
    if(100%k==0)
    {
        cout<<endl<<100/k;
    }
    else
    {
        int x;
        x=gcd(k,100);
        cout<<endl<<100/x;
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