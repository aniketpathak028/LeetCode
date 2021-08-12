#include<bits/stdc++.h>

typedef unsigned long long int  ulli;
typedef long long int lli;

const int mod = 1e9+7;

using namespace std;

void solve()
{
    lli n,x,t;
    cin>>n>>x>>t;
    
    lli diff= t/x;// number of multiples of x leass than or equal to t

    if(diff==0 || n-1==0)
    {
        cout<<0<<endl;
        return;
    }

    else if(n-1<diff) // in-case the number of numbers are less than multiples
    {
        lli alt_ans1= n-1; 
        lli alt_ans2= (n-2)*(n-1)/2;
        cout<<alt_ans1+alt_ans2<<endl;
    }
    else
    {
            lli ans1= (n-diff)*diff; // sum till n-diff
            lli ans2= (diff-1)*diff/2; // sum after n-diff
            cout<<ans1+ans2<<endl;
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli k;
    cin>>k;
    while(k--)
    {
        solve();
    }
    return 0;
}