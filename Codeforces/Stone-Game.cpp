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
        int n,i;
        cin>>n;
        int a[n];
        
        int minimum=INT_MAX;
        int maximum=INT_MIN;
        int v,x;

        for(i=0;i<n;i++){
            cin>>a[i];
            if(a[i]<minimum){
                minimum=a[i];
                v=i;
            }
            if(a[i]>maximum){
                maximum=a[i];
                x=i;
            }
        }

        v+=1;
        x+=1;

        int l,m,o;
        l= max(v,x);
        m= max(n-v,n-x)+1;
        o= min(v,x)+n-max(v,x)+1;
        cout<<min(l,min(m,o))<<endl;
    }
    return 0;
}