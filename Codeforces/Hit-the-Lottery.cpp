#include<bits/stdc++.h>

typedef unsigned long long int  ulli;
typedef long long int lli;

const int mod = 1e9+7;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int count=0;
    while(n)
    {
        if(n>=100)
        {
            count+=n/100;
            n=n%100;
        }
        else if(n>=20)
        {
            count+=n/20;
            n=n%20;
        }
        else if(n>=10)
        {
            count+=n/10;
            n=n%10;
        }
        else if(n>=5)
        {
            count+=n/5;
            n=n%5;
        }
        else
        {
            n=n-1;
            count++;
        }
    }

    cout<<count<<endl;
    return 0;
}