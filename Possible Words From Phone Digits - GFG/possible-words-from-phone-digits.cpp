// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    void words(int i, int a[], int N, string w, vector<string> &k, vector<string> &ans){
        if(i==N){
            ans.push_back(w);
            return;
        }
        
        string key= k[a[i]];
        for(int j=0; j<key.length(); j++){
            words(i+1, a, N, w+key[j], k, ans);
        }
    }
    vector<string> possibleWords(int a[], int N)
    {
        vector<string> k(10);
        k[2]= "abc";
        k[3]="def";
        k[4]="ghi";
        k[5]="jkl";
        k[6]="mno";
        k[7]="pqrs";
        k[8]="tuv";
        k[9]="wxyz";
        vector<string> ans;
        words(0, a, N, "", k, ans);
        return ans;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends