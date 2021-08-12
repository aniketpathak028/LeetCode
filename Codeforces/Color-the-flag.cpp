#include<bits/stdc++.h>

typedef unsigned long long int  ulli;
typedef long long int lli;

const int mod = 1e9+7;

using namespace std;

 
void solve()
{
    int n,m;
    cin>>n>>m;
    int a[n][m];
    
    for(int i=0;i<n;i++)
    {
      string color;
      cin>>color;

      for(int j=0;j<m;j++)
      {
        if(color[j]=='.')
        {
          a[i][j]=-1;
        }
        else if(color[j]=='R')
        {
          a[i][j]=0;
        }
        else
        {
          a[i][j]=1;
        }
      }
    }

    int case1[n][m];

    for(int i=0;i<n;i++)
    {
      bool f=0;
      if(i&1)f=1;
      for(int j=0;j<m;j++)
      {
        if(!f)ans1[i][j]=0;
        else ans1[i][j]=1;
        f=!f;
      }
     
    }

    int ans2[n][m];
    for(int i=0;i<n;i++){
      bool f=1;
      if(i&1)f=0;
      for(int j=0;j<m;j++){
        if(!f)ans2[i][j]=0;
        else ans2[i][j]=1;
        f=!f;
        // cout<<ans2[i][j];
      }
      // cout<<endl;
    }

    bool ans=1;
 
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(arr[i][j]!=-1 and (arr[i][j]!=ans1[i][j])){
          // cout<<arr[i][j]<<" "<<ans1[i][j]<<endl;
          ans=0;
          break;
        }
      }
      if(!ans)break;
    }
    if(ans){
      cout<<"Yes"<<endl;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(ans1[i][j]==0)cout<<'R';
        else cout<<'W';
      }
      cout<<endl;
    }
    }
    else{
      ans=1;
      for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(arr[i][j]!=-1 and arr[i][j]!=ans2[i][j]){
          ans=0;
          break;
        }
      }
      if(!ans)break;
    }
    if(ans){
      cout<<"Yes"<<endl;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(ans2[i][j]==0)cout<<'R';
        else cout<<'W';
      }
      cout<<endl;
    }
    }

    else
    {
      cout<<"No"<<endl;
    }

    }
 
    
}

int main()
{
      ios_base::sync_with_stdio(0);
      cin.tie(0);

        int t;
        cin>>t;
      
      while(t--)
      {
            solve();
      }
      return 0;
}