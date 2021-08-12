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
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int count=0;
    int max= a[0];
    int min= a[0];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[j]>max)
            {
                max= a[j];
            }
            if(a[j]<min)
            {
                min=a[j];
            }
        }
        if(a[i]>max || a[i]<min)
        {
            count++;
        }
    }
    cout<<count;
    return 0;
}