#include<bits/stdc++.h>

typedef unsigned long long int  ulli;
typedef long long int lli;

const int mod = 1e9+7;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    set<char> d;
    string s; cin >> s;
    for(char i:s) d.insert(i);
    if(d.size()%2!=0) cout << "IGNORE HIM!";
    else cout << "CHAT WITH HER!";
    return 0;
}