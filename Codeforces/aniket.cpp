#include<bits/stdc++.h>

typedef unsigned long long int  ulli;
typedef long long int lli;

const int mod = 1e9+7;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli t;
    cin>>t;
    while(t--)
    {
        lli n;
    cin>>n;

    vector<lli> v(2*n+1, -1);


    for(int i=1;i<=n;i++)
    {
        lli a;
        cin>>a;
        v[a]= i;
    }

    int count= 0;

    for(int sum= 0;sum< 2*n-1; sum++)
    {
        for(lli i=0;i*i<= sum;i++){
            if(sum%i==0 && i*i!=sum && v[i]!=-1 && v[sum/i]!=-1 && v[i]+v[sum/i]==sum)
            count++;
        }

    }
    cout<<count<<endl;
    }
    return 0;
}