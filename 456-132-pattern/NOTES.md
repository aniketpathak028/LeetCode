**Naive Approach O(n^3)**
```
// Brute force approach O(n^3)
bool find132pattern(vector<int>& nums) {
int n= nums.size();
if(n==1 || n==2) return false; // nums has less than 3 elements
for(int i=1; i<n-1; ++i){
int mid= nums[i]; // check for all 3's in 132
for(int j=0; j<i; ++j){
if(nums[j]<mid){
int left= nums[j]; // check for all 1's in 132
for(int k=i+1; k<n; ++k){
if(nums[k]<mid && nums[k]>left){ // check for all 2's in 132
return true;// return true if a pattern in found
}
}
}
}
}
return false;
}
```
​