#include<bits/stdc++.h>

typedef unsigned long long int  ulli;
typedef long long int lli;

const int mod = 1e9+7;

using namespace std;

void solve()
{
    int a[4];
    int b[4];
    for(int i=0;i<4;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }

    sort(a, a + 4);

    int p1= a[2];
    int p2= a[3];

        if((b[0]== p1 && b[1]==p2) || (b[0]== p2 && b[1]==p1))
        {
            cout<<"NO"<<endl;
        }
        else if ((b[2]== p1 && b[3]==p2) || (b[2]== p2 && b[3]==p1))
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
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