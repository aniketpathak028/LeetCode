int solve(int s, int e, string &str){
// base-case
if(s>e) return 0; // start index exceeds end index
if(s==e) return 1; // string with 1 character is a palndrome
char c1= str[s], c2= str[e]; // first and last character in the current string
int tot_count= 0;
if(c1==c2){
// if(c1==c2) => solve(c1mc2)= solve(c1m) + solve(mc2) - solve(m)
tot_count= solve(s, e-1, str) + solve(s+1, e, str) - solve(s+1, e-1, str);
}
else{
// if(c1!=c2) => solve(c1mc2)= solve(c1m) + solve(mc2) + 1
tot_count= solve(s, e-1, str) + solve(s+1, e, str) + 1;
}
return tot_count;
}
int countSubstrings(string s) {
int n= s.size()-1;
return solve(0, n, s);
}