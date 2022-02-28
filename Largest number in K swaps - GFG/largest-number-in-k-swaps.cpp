// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
   string s;
   void answer(string curr,int k,int i){
       if(k==0 || i==s.size()){
           if(s<curr){
               s=curr;
           }
           return;
       }
       
       for(int j=i;j<curr.size();++j){
           if(curr[j]<=curr[i] && i!=j){
               continue;
           }
           
           swap(curr[j],curr[i]);
           // saving the swap when i=j;
           if(i==j){
               answer(curr,k,i+1);
           }
           answer(curr,k-1,i+1);
           swap(curr[j],curr[i]);
       }
       return ;
       
   }
   //Function to find the largest number after k swaps.
   string findMaximumNum(string str, int k)
   {
      s=str;
      answer(str,k,0);
      return s;
   }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends