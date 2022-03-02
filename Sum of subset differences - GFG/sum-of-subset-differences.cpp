// { Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std;

int sumDiff(int S[], int n);

 
// Driver program to test above function
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
   	int n;
   	cin>>n;
   	int S[n];
   	for(int i=0;i<n;i++)
   	cin>>S[i];
    cout<<sumDiff(S, n)<<endl;;
   }
  
    return 0;
}// } Driver Code Ends


/*You are required to complete this method */
int sumDiff(int S[], int n)
{
    int sum=0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            sum+= (S[j]-S[i])*(pow(2, j-i-1));
        }
    }
    
    return sum;
}