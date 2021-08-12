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

    char alpha[26];

    for (int i = 0; i < 26; i++)
    {
        alpha[i] = 'a' + i;
    }

    string s;
    while(t--)
    {
        cin >> s;

        int len = s.size();
        vector<bool> value(len, 0);

        for (int i = 1; i <= len-2;i++)
        {
            if(s[i]>s[i-1] && s[i]>s[i+1])
            {
                value[i] = 1;
            }

        }

        if (std::find(value.begin(), value.end(), 1) != value.end())
        {
            std::cout << "NO"<<endl;
        }
        else
        {
            std::cout << "YES"<<endl;
        }
    }
    return 0;
}